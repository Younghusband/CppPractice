//
// Created by Younghusband on 2024/8/7.
//


#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

#include <unordered_map>
#include <vector>


using namespace std;

class Solution {

public:
    int GetMinPriceDiff(const vector<int>& prices)
    {
        //  先找到最小价格差
        int gcnt = 0;
        int min_sub = 10001;
        int pre = prices[0];

        // startIndex , group
        unordered_map<int, vector<int>> helper;

        vector<int> sorted_prices = prices;

        // 1.排序   1 3 5 7 12
        sort(sorted_prices.begin(), sorted_prices.end());
        for(int i = 1; i < sorted_prices.size(); i++) {
            int cursub = sorted_prices[i] - pre;
            pre = sorted_prices[i];
            min_sub = min(min_sub, cursub);
        }

        // 2. 找到组合
        int start = 0;
        for(int i = 0; i < sorted_prices.size() - 1; i++) {
            // 属于最小差
            if(sorted_prices[i + 1] - sorted_prices[i] == min_sub) {
                // 不属于新建
                if(helper.find(start) != helper.end()) {
                    helper[start].push_back(sorted_prices[i + 1]);
                } else {
                    helper[start].push_back(sorted_prices[i]);
                    helper[start].push_back(sorted_prices[i + 1]);
                }
            }
            // 如果不属于价格差, 开启新的组判断
            else {
                start = i + 1;   //  1 1 90 90 90
            }
        }

        for(const auto& pair: helper) {
            int x = pair.second.size();
            gcnt += (x - 1);

        }
        return gcnt;
    }
};


int main() {
    Solution solution;
    int result = solution.GetMinPriceDiff({1, 3, 7, 5, 12});
    cout << result << endl;
}