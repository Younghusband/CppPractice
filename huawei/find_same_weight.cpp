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

    int cnt_binary_one(const long long target) {
        int temp = target;
        int res = 0;
        while(temp != 0) {
            res += temp % 2 == 1 ? 1 : 0;
            temp >>= 1;
        }
        return res;
    }

    int GetNumCount(long long minNum, long long maxNum, int weight)
    {
        int cnt = 0;
        // 在lowBit 和 highBit 之间做排列组合
        string mask(32 - weight, '0');
        mask += string(weight, '1');
        // 遍历排列
        do {
            // 根据mask获取数值
            long long cur = bitset<32>(mask).to_ullong();
            // 判断数值
            cnt += judgeIn(minNum, maxNum, cur);
        } while(next_permutation(mask.begin(), mask.end()));
        return cnt;
    }

    // 根据min 和 max 得到 最高位数和最低位数 二进制数

};

// int main() {
//     Solution slo;
//     // long long max = (1LL << 32) - 1;
//     // long long min = 0;
//     long long max, min;
//     int weight;
//     cin >> min;
//     cin >> max;
//     cin >> weight;
//
//     int res = slo.GetNumCount(min, max, weight);
//     cout << res << endl;
// }

