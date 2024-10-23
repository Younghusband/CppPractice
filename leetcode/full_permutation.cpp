#include <algorithm>
#include <vector>
/**
 * 全排列
 */

using namespace std;
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            vector<int> cur = nums;
            res.push_back(cur);
        } while(next_permutation(nums.begin(), nums.end()));
        return res;
    }

    // 传统回溯法
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<bool> visited(nums.size(), false);
    //     bt(nums, visited);
    //     return res;
    // }


    void bt(vector<int>& nums, vector<bool>& visited) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            bt(nums, visited);
            path.pop_back();
            visited[i] = false;
        }
    }

};