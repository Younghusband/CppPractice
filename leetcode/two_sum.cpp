//
// Created by Younghusband on 2024/8/6.
//


#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        int sub = target - nums[i];
        auto it = map.find(sub);
        if(it != map.end()) {
            return {it->second, i};
        }
        map[nums[i]] = i;
    }
    return {};
}