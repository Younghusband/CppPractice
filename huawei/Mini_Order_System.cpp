//
// Created by Younghusband on 2024/9/6.
//

#include <string>
#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <type_traits>
#include <cctype>
#include <stdexcept>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class OrderSystem {
public:

    unordered_map<int, vector<string>> CMap;
    unordered_map<string, vector<int>> GMap;

    // 待实现函数，在此函数中填入答题代码
    OrderSystem()
    {
    }

    // 待实现函数，在此函数中填入答题代码
    void Order(int customerId, const vector<string>& goods)
    {
        // 更新用户订购列表
        for(const auto& good: goods) {
            CMap[customerId].push_back(good);
            GMap[good].push_back(customerId);
        }
    }

    void deliverSpecificGood(const string& good) {
        if(GMap.find(good) != GMap.end()) {
            auto& customers = GMap[good];
            int cid = customers[0];
            // 先操作CMap
            auto& cgood = CMap[cid];
            auto it = find(cgood.begin(), cgood.end(), good);
            cgood.erase(it);

            // 再操作GMap
            customers.erase(customers.begin());
        }
    }

    // 待实现函数，在此函数中填入答题代码
    void Deliver(const vector<string>& goods)
    {
        for(const auto& good: goods) {
            deliverSpecificGood(good);
        }
    }

    // 待实现函数，在此函数中填入答题代码
    int Query()
    {
        int maxCnt = 0;  // 这里很关键
        int maxId = -1;
        for(const auto& pair : CMap) {
            int cid = pair.first;
            int cnt = pair.second.size();

            if(cnt > maxCnt) {
                maxCnt = cnt;
                maxId = cid;
            } else if(cnt == maxCnt) {
                maxId = min(cid, maxId);
            }
        }

        return maxId;
    }

};

int main() {
    OrderSystem s;
    s.Order(99, {"gd1000"});
    s.Order(88, {"gd666", "gd555"});
    s.Order(99, {"gd666"});
    cout << s.Query() << endl;
    s.Deliver({"gd666"});
    cout << s.Query() << endl;

}