#include <algorithm>
#include <vector>
//
// Created by Younghusband on 2024/8/14.
//
class Solution {
public:

    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n - k,nums.end());
        return nums[n - k];
    }

};