//
// Created by Younghusband on 2024/8/6.
//


#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indexMap = {};
    for(int i = 0; i < nums.size(); i++) {
        auto it = indexMap.find(target - nums[i]);
        if(it != indexMap.end()) {
            return {it->second, i};
        }
        indexMap[nums[i]] = i;
    }
    return {};
}