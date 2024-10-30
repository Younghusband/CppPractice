// /*
//  * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
//  * Description: 上机编程认证
//  * Caution：本地调试时，只编译运行main.cpp文件，不要链接这个文件！因为本文件已经被main.cpp文件include了
//  */
//
// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <vector>
// #include <utility>
//
// using namespace std;
//
// class Repo {
// public:
//     int pId;
//     int repoId;
//     int lanId;  // 0~6
//     int codeline;
//
//     Repo(int pid, int repoId, int lanId, int codeline) : pId(pid), repoId(repoId), lanId(lanId), codeline(codeline) {
//     }
//
// };
//
// class CodeStatsSystem {
// public:
//     map<int, vector<Repo>> data; // productId -> repoId languageId codeline
//     map<int, int> repo2Pid; // repoId -> productId
//
//     vector<Repo> create(int pid, vector<int> repos) {
//         vector<Repo> res;
//         for(int repId : repos) {
//             Repo repo(pid, repId, -1, 0);
//             repo2Pid[repId] = pid;
//             res.push_back(repo);
//         }
//         return res;
//     }
//
//     CodeStatsSystem(const vector<pair<int, vector<int>>>& products)
//     {
//         for(auto const& item: products) {
//             int pid = item.first;
//             vector<int> repos = item.second;
//             // vector<Repo> rs = create(pid, repos);
//
//             vector<Repo> res;
//             for(int repId : repos) {
//                 Repo repo(pid, repId, -1, 0);
//                 repo2Pid[repId] = pid;
//                 res.push_back(repo);
//             }
//             data[pid] = res;
//         }
//     }
//
//     int changelines(int repoId, vector<Repo>& repos, int& codeline, int& lanId) {
//         set<int> set;
//         for(auto const& item: repos) {
//             if(item.lanId != -1) {
//                 set.insert(item.lanId);
//             }
//         }
//
//         bool exists = set.count(lanId) > 0;
//         for(auto & r : repos) {
//             if(r.repoId != repoId) {
//                 continue;
//             }
//             if(!exists && r.lanId != -1) {
//                 Repo repo(r.pId, r.repoId, lanId, codeline);
//                 repos.push_back(repo);
//                 return codeline;
//             } else {
//                 if(r.lanId == -1) {
//                     r.lanId = lanId;
//                     r.codeline = codeline;
//                     return r.codeline;
//                 }
//                 if(r.lanId == lanId) {
//                     r.codeline += codeline;
//                     return r.codeline;
//                 }
//             }
//         }
//         return 0;
//     }
//
//
//     int ChangeCodelines(int repoId, int languageId, int codeline)
//     {
//         // find pid
//         if(repo2Pid.find(repoId) == repo2Pid.end()) {
//             return 0;
//         }
//
//         int pid = repo2Pid[repoId];
//         // change repo
//         int afterChange = changelines(repoId, data[pid], codeline, languageId);
//         return afterChange;
//     }
//
//     bool compareM(const pair<int, int>& p1, const pair<int, int>& p2) {
//         return p1.second < p2.second;
//     }
//
//     static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
//         if(a.second == b.second)
//             return a.first < b.first;
//         return a.second > b.second;
//     }
//
//     void clearInvalid(vector<Repo>& rps) {
//         for(auto it = rps.begin(); it < rps.end(); it++) {
//             if(it->lanId == -1) {
//                 rps.erase(it);
//             }
//         }
//     }
//
//     vector<Repo> getRp(int pid) {
//         vector<Repo> res;
//         if(pid == 0) {
//             for(auto & item: data) {
//                 // clearInvalid(item.second);
//                 res.insert(res.end(), item.second.begin(), item.second.end());
//             }
//         } else {
//             res = data[pid];
//         }
//         return res;
//     }
//
//     vector<int> StatLanguage(int productId)
//     {
//         if(data.find(productId) == data.end() && productId != 0) {
//             return {};
//         }
//         vector<Repo> repos = getRp(productId);
//         map<int, int> lanc;  // lan -> totalCode
//         for(const auto& r : repos) {
//             int lan = r.lanId;
//             if(lan == -1) {
//                 continue;
//             }
//             int old = lanc[lan];
//             lanc[lan] = old + r.codeline;
//         }
//
//         // priority_queue<pair<int, int>, compareM> pq(compareM);
//         vector<pair<int, int>> v;
//         for(auto const& item: lanc) {
//             v.push_back(make_pair(item.first, item.second));
//         }
//
//         sort(v.begin(), v.end(), comparePairs);
//         vector<int> res;
//         for(auto const& item : v) {
//             res.push_back(item.first);
//         }
//         return std::move(res);
//     }
// };
//
//
// int main() {
//
//     // CodeStatsSystem([[10, [102, 101]], [12, [122]], [22, [221]]])
//     // changeCodelines(221, 3, 2500)
//     // changeCodelines(102, 2, 2100)
//     // changeCodelines(101, 1, 2000)
//     // statLanguage(10)
//     // statLanguage(22)
//     // changeCodelines(102, 2, -100)
//     // statLanguage(0)
//
// //     CodeStatsSystem([[10, [102, 101]], [11, [110]], [20, [201]]])
//
//
//
//     vector<pair<int, vector<int>>> products;
//     vector<int> v1 = {102, 101};
//     vector<int> v2 = {110};
//     vector<int> v3 = {201};
//
//     products.push_back(make_pair(10, v1));
//     products.push_back(make_pair(11, v2));
//     products.push_back(make_pair(20, v3));
//     CodeStatsSystem s(products);
//
//
//     // changeCodelines(201, 0, 2)
//     // changeCodelines(110, 2, 0)
//     // changeCodelines(102, 5, 1)
//     // changeCodelines(102, 5, -1)
//     // statLanguage(10)
//     // changeCodelines(110, 2, 0)
//     // changeCodelines(110, 2, 0)
//
//     cout << s.ChangeCodelines(201, 0, 2) << endl;
//     cout << s.ChangeCodelines(110, 2, 0) << endl;
//     cout << s.ChangeCodelines(102, 5, 1) << endl;
//     cout << s.ChangeCodelines(102, 5, -1) << endl;
//     vector<int> x = s.StatLanguage(10);
//
//     cout << x[0] << endl;
//
//
//     cout << "";
//
//
//     // vector<int> vec = {1, 2};
//     // vector<int> vec1 = {3, 4};
//     //
//     // vec.insert(vec.end(), vec1.begin(), vec1.end());
//     //
//     // vec.erase(vec.begin());
//     //
//     // cout << "";
//
// }