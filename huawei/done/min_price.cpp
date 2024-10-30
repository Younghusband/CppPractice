//
// Created by Younghusband on 2024/10/29.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getMinGap(const vector<int>& data) {
        int res = 1000;
        for(size_t i = 1; i < data.size(); i++) {
            res = min(data[i] - data[i - 1], res);
        }
        return res;
    }

    int getGroupsByDataAndGap(const vector<int>& data, const int gap) {
        int cnt = 0;
        if(gap == 0) {
            int cur_range = 1;
            for(size_t i = 1; i < data.size(); i++) {
                if(data[i] - data[i - 1] == gap) {
                    cur_range++;
                }
                // 到头了 或者 换组了
                if(i == data.size() - 1 || data[i] - data[i - 1] != gap) {
                    cnt += (cur_range * (cur_range - 1)) / 2;
                    cur_range = 1;
                }
            }
            return cnt;
        }
        for(size_t i = 1; i < data.size(); i++) {
            if(data[i] - data[i - 1] == gap) {
                cnt++;
            }
        }
        return cnt;
    }

    int GetMinPriceDiff(const vector<int>& prices)
    {
        vector<int> data = prices;
        sort(data.begin(), data.end());
        return getGroupsByDataAndGap(data, getMinGap(data));
    }
};

// int main() {
//     // [90, 98, 90, 90, 1, 1]
//     Solution slo;
//     int res = slo.GetMinPriceDiff({90, 98, 90, 90, 1, 1});
//     cout << res << endl;
//
// }