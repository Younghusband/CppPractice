/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: 上机编程认证
 *
 * 科目一专业级第一题
 * tips: 1. 构造函数的使用 2. map中放对象的时候，需要给一个默认空构造
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

struct Repo {
public:
    int pId;
    int repoId;
    unordered_map<int, int> lanCodeMap;
    Repo(int pid, int repoId) : pId(pid), repoId(repoId) {}
    Repo() {}
};

class CodeStatsSystem {
public:
    unordered_map<int, vector<int>> product2Repos; // productId -> [repoId] languageId codeline
    unordered_map<int, Repo> repoMap;  // repo data

    CodeStatsSystem(const vector<pair<int, vector<int>>>& products)
    {
        for(auto const& item: products) {
            int pid = item.first;
            vector<int> repos = item.second;
            product2Repos[pid] = repos;
            vector<Repo> res;
            for(int repId : repos) {
                repoMap[repId] = Repo(pid, repId);
            }
        }
    }

    int changelines(Repo& repo, int codeline, int lanId) {
        repo.lanCodeMap[lanId] += codeline;
        return repo.lanCodeMap[lanId];
    }

    int ChangeCodelines(int repoId, int languageId, int codeline) {
        // find pid
        if(repoMap.find(repoId) == repoMap.end()) {
            return 0;
        }
        // change repo
        int afterChange = changelines(repoMap[repoId], codeline, languageId);
        return afterChange;
    }

    vector<int> getReposByPid(int pid) {
        if(product2Repos.find(pid) == product2Repos.end() && pid != 0) {
            return {};
        }
        if(pid != 0) {
            return product2Repos[pid];
        } else {
            // 逐个pid 添加repo
            vector<int> res;
            for(auto const& pair : product2Repos) {
                res.insert(res.end(), pair.second.begin(), pair.second.end());
            }
            return res;
        }
    }

    vector<int> StatLanguage(int productId)
    {
        // 获取所有仓库
        vector<int> repoIds = getReposByPid(productId);
        if(repoIds.size() == 0) return {};
        map<int, int> lanc;  // lan -> totalCode
        // 按照仓库追加
        for(int repoId : repoIds) {
            if(repoMap.find(repoId) == repoMap.end()) {
                continue;
            }
            Repo cur = repoMap[repoId];
            unordered_map<int, int> lan2Code = cur.lanCodeMap;
            if(lan2Code.size() == 0) {
                continue;
            }
            for(auto const& pair : lan2Code) {
                int lanId = pair.first;
                int codeline = pair.second;
                lanc[lanId] += codeline; // 不存在就是0？
            }
        }

        auto cmp = [] (const pair<int, int>& p1, const pair<int, int>& p2) {
            if(p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto const& item: lanc) {
            if(item.second > 0) {
                pq.push(make_pair(item.first, item.second));
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            pair<int, int> tpD = pq.top();
            res.push_back(tpD.first);
            pq.pop();
        }
        return res;
    }
};


// int main() {
//     // CodeStatsSystem([[10, [102, 101]], [12, [122]], [22, [221]]]);
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
//     vector<pair<int, vector<int>>> products;
//     vector<int> v1 = {102, 101};
//     vector<int> v2 = {122};
//     vector<int> v3 = {221};
//
//     products.push_back(make_pair(10, v1));
//     products.push_back(make_pair(12, v2));
//     products.push_back(make_pair(22, v3));
//     CodeStatsSystem s(products);
//
//
//     cout << s.ChangeCodelines(221, 3, 500) << endl;
//     cout << s.ChangeCodelines(102, 2, 1900) << endl;
//     cout << s.ChangeCodelines(101, 1, 2000) << endl;
//     cout << s.ChangeCodelines(101, 2, 200) << endl;
//
//     vector<int> x = s.StatLanguage(10);
//     for(int a: x) {
//         cout << a << endl;
//     }
//     // cout << s.ChangeCodelines(102, 3, 2000) << endl;
//     // cout << s.ChangeCodelines(102, 2, -100) << endl;
//
//     vector<int> z = s.StatLanguage(20);
//     for(int a: z) {
//         cout << a << endl;
//     }
//
//     cout << s.ChangeCodelines(102, 3, 2000) << endl;
//     cout << s.ChangeCodelines(102, 2, -100) << endl;
//
//     vector<int> y = s.StatLanguage(0);
//     for(int a: y) {
//         cout << a << endl;
//     }
//
//     cout << "";
//
// }