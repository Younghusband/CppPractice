//
// Created by Younghusband on 2024/9/3.
//


#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {

unordered_map<int, int> freqMap;
public:
    static bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        for(int num: nums) {
            freqMap[num] += 1;
        }

        // map 2 vec
        vector<pair<int, int>> vec(freqMap.begin(), freqMap.end());
        sort(vec.begin(), vec.end(), compare);
        int n = vec.size();
        for(int i = n - 1; i >= n - k; i--) {
            res.push_back(vec[i].first);
        }
        return res;
    }

};


// int main() {
//     Solution slo;
//     vector<int> vec = {1,1,1,2,2,3};
//     int k = 2;
//
//     for(int num: slo.topKFrequent(vec, k)) {
//         cout << num << ", ";
//     }
// }