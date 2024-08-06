//
// Created by Younghusband on 2024/8/6.
//
#include <vector>
#include <algorithm> // 用于 std::swap
#include <iostream>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, const int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]); // 交换元素
        backtrack(nums, result, start + 1); // 递归
        swap(nums[start], nums[i]); // 恢复原状
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

// int main() {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> result = permute(nums);
//     // 打印结果 const auto& 是个万能类型吧？
//     for (const auto& item : result) {
//     // for (vector<int> item : result) {
//         for (int num : item) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
//
//     return 0;
// }

