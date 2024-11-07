//
// Created by Younghusband on 2024/9/3.
//


#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>
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
        // vector<pair<int, int>> vec(freqMap.begin(), freqMap.end()); // map 2 vec
        auto cmp = [&] (const pair<int, int> p1, const pair<int, int> p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto const& pair : freqMap) {
            if(pq.size() < k) {
                pq.push(pair);
            }
            // 满了
            else {
                if(pair.second > pq.top().second) {
                    pq.push(pair);
                    pq.pop();
                }
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
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