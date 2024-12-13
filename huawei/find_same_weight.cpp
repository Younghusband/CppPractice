//
// Created by Younghusband on 2024/10/17.
//

#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:

    bool judgeIn(long long min, long long max, long long target) {
        return target >= min && target < max;
    }

    int leftPos(long long target) {
        int left = 32;
        int right = 0;
        int cur;

        if(target > (2 << left)) return left;
        while(true) {
            if(target <= (2 << cur) && target > (2 << (cur - 1))) {
                break;
            }

            if(target < (2 << cur)) {
                cur = (left + right) >> 1;

            }

        }

    }

    int GetNumCount(long long minNum, long long maxNum, int weight)
    {
        int cnt = 0;
        // 在lowBit 和 highBit 之间做排列组合
        string mask(32 - weight, '0');
        mask += string(weight, '1');   // 拼出 0000...000000011
        // 遍历排列
        do {
            cout << mask << endl;
            // 根据mask获取数值
            long long cur = bitset<32>(mask).to_ullong();
            // 判断数值
            cnt += judgeIn(minNum, maxNum, cur);
        }
        while(next_permutation(mask.begin(), mask.end()));
        return cnt;
    }
};

int main() {
    Solution slo;
    // long long max = (1LL << 32) - 1;
    long long max = 8;
    long long min = 0;
    int weight;
    cin >> min;
    cin >> max;
    cin >> weight;

    int res = slo.GetNumCount(min, max, weight);
    cout << res << endl;
}

