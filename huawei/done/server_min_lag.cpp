//
// Created by Younghusband on 2024/10/12.
//
#include <algorithm>
#include <vector>


using namespace std;
int ClusterLatency(const vector<int>& arr)
{
    vector<int> nums = arr;
    int totalLag = 0;
    sort(nums.begin(), nums.end());
    int targetIndex = nums.size() / 2;
    for(int num: nums) {
        totalLag += abs(num - nums[targetIndex]);
    }
    // 在此添加你的代码
    return totalLag;
}

// int main() {
//     vector<int> arr = {2, 6, 4};
//     ClusterLatency(arr);
// }

