//
// Created by Younghusband on 2024/10/26.
//
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class AssetsSystem {
public:

    set<int> aid;
    unordered_map<int, int> aidPersonMap;
    unordered_map<int, int> personCntMap;  // 读者 计数

    AssetsSystem()
    {}

    int AddAssets(int assetsId)
    {
        if(aid.count(assetsId) > 0) {
            return 0;
        }
        aid.insert(assetsId);
        return 1;
    }

    int BorrowAssets(int employeeId, int assetsId)
    {
        // 无资产
        if(aid.count(assetsId) == 0) {
            return -1;
        }
        // 资产被借走
        if(aidPersonMap.find(assetsId) != aidPersonMap.end()) {
            return 0;
        }
        aidPersonMap[assetsId] = employeeId;
        personCntMap[employeeId] += 1;
        return 1;
    }

    int ReturnAssets(int assetsId)
    {
        if(aid.count(assetsId) == 0) {
            return -1;
        }
        // 资产未被借走
        if(aidPersonMap.find(assetsId) == aidPersonMap.end()) {
            return 0;
        }
        int pid = aidPersonMap[assetsId];
        aidPersonMap.erase(assetsId);
        personCntMap[pid] -= 1;
        return 1;
    }

    vector<pair<int, int>> StatAssets(int topNum)
    {
        auto cmp = [] (const pair<int, int> p1, const pair<int, int> p2) {
            if(p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(auto const& pair : personCntMap) {
            if(pair.second != 0) {
                pq.push(pair);
            }
        }

        vector<pair<int, int>> res;
        int cnt = 0;
        while(!pq.empty() && cnt < topNum) {
            pair<int, int> top = pq.top();
            res.push_back(top);
            pq.pop();
            cnt++;
        }

        return res;
    }
};

int main() {
    // AssetsSystem()
    // addAssets(1812)
    // borrowAssets(99527, 1812)
    // addAssets(1812)
    // statAssets(2)
    // returnAssets(1812)

    AssetsSystem s;
    s.AddAssets(1234);
    s.BorrowAssets(99527, 1234);
    s.ReturnAssets(1234);
    s.StatAssets(1);

}
