//
// Created by Younghusband on 2024/10/23.
//
#include <vector>

using namespace std;
class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

private:
    void backtrack(vector<int>& nums,
                   int start) {

        // 将当前子集添加到结果中
        result.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]); // 选择当前元素
            backtrack(nums, i + 1); // 递归调用
            path.pop_back(); // 回溯，撤销选择
        }
    }
};