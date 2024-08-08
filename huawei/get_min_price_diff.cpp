//
// Created by Younghusband on 2024/8/8.
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

        // startIndex , group
        vector<int> sorted_prices = prices;
        // 1.排序   1 3 5 7 12
        sort(sorted_prices.begin(), sorted_prices.end());
        for(int i = 1; i < sorted_prices.size(); i++) {
            min_sub = min(min_sub, sorted_prices[i] - sorted_prices[i - 1]);
        }

        // 2. 找到组合
        for(int i = 1; i < sorted_prices.size(); i++) {
            if(sorted_prices[i] - sorted_prices[i - 1] == min_sub) {
                gcnt++;
            }
        }

        return gcnt;
    }
};

// int main() {
//     Solution solution;
//     // int result = solution.GetMinPriceDiff({90, 98, 90, 90, 1, 1});
//     int result = solution.GetMinPriceDiff({1, 3, 7, 5, 12});
//     cout << result << endl;
// }
