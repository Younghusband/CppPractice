//
// Created by Younghusband on 2024/9/18.
//

#include <iostream>

using namespace std;

class Solution {

    string toBi(long num) {
        if(num == 0) return "0";
        string biStr = "";
        while(num > 0) {
            biStr = (num % 2 == 0 ? "0" : "1") + biStr;  // 逆序相加
            num = num >> 1;
        }
        return biStr;
    }


public:
    // 待实现函数，在此函数中填入答题代码
    int GetLongestNum(long num)
    {
        string biStr = toBi(num);
        if(biStr.size() == 1) return 1;
        int left = 0;
        int right = left + 1;
        int maxlen = 1;
        while(right <= biStr.size() - 1) {
            if(biStr[right] == biStr[left]) {
                maxlen = max(maxlen, right - left + 1);
                right++;
            } else {
                left++;
            }
        }
        return maxlen;
    }
};


// int main() {
//
//     long num;
//     cin >> num;
//     Solution slo;
//     cout << slo.GetLongestNum(num);
//
// }
