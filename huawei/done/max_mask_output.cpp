//
// Created by Younghusband on 2024/10/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int startIndex = 0;
    int GetMaxQuantity(const vector<int>& productions, const vector<int>& plans, int window)
    {
        int len = productions.size();
        int max_out = 0;
        int left = 0;
        int right = left + window - 1;
        int preSum = 0;
        int afterSum = 0;
        for(int i = right + 1; i < len; i++) {
            if(plans[i] == 1) {
                afterSum += productions[i];
            }
        }
        int windowValue = 0;
        for(int i = left; i <= right; i++) {
            windowValue += productions[i];
        }

        while(right < len) {
            int curSum = preSum + windowValue + afterSum;
            max_out = max(curSum, max_out);
            preSum += plans[left] ? productions[left] : 0;
            afterSum -= plans[right + 1] ? productions[right + 1] : 0;
            windowValue -= productions[left];
            windowValue += productions[right + 1];
            left++;
            right++;
        }
        return max_out;
    }

};

// int main() {
//
//     Solution slo;
//     slo.GetMaxQuantity({803, 804, 805, 802, 803, 804, 805, 804}, {1, 0, 1, 0, 1, 0, 1, 0}, 3);
//     // vector<int> sss = {1, 0, 1, 0, 1, 0, 1, 0};
//     // cout << sss[8] << endl;
//
//     // if(sss[8])
//
//
// }