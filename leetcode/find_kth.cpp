#include <algorithm>
#include <queue>
#include <vector>
//
// Created by Younghusband on 2024/8/14.
//
using namespace std;
class Solution {
public:

    // int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     std::nth_element(nums.begin(), nums.begin() + n - k,nums.end());
    //     return nums[n - k];
    // }

    // int findKthLargest(vector<int>& nums, int k) {
    //     // 倒序排序，拿k-1
    //     sort(nums.begin(), nums.end(), std::greater<int>());
    //     return nums[k - 1];
    // }

    void heapify(vector<int>& data, int i, int heapSize) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (left < heapSize && data[left] > data[largest]) {
            largest = left;
        }
        if (right < heapSize && data[right] > data[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(data[i], data[largest]);
            heapify(data, largest, heapSize);
        }
    }

    void heapSort(vector<int>& data, int k) {
        int n = data.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(data, i, n);
        }
        for (int i = n - 1; i >= n - k; i--) {
            swap(data[0], data[i]);
            heapify(data, 0, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heapSort(nums, k);
        return nums[n - k];
    }

    // 大根堆
    // int findKthLargestUsingQueue(vector<int>& nums, int k) {
    //     priority_queue<int> queue;
    //     for(const auto& num: nums) {
    //         queue.push(num);
    //     }
    //     for(int i = 1; i <= k; i++) {
    //         if(i == k) {
    //             return queue.top();
    //         }
    //         queue.pop();
    //     }
    // }

    // 小根堆
    int findKthLargestUsingQueue(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;  // 如果需要greater的话，中间的vector就是必须的了
        for(const auto& num: nums) {
            if(queue.size() < k) {
                queue.push(num);
            } else {
                int top = queue.top();
                if(num >= top) {
                    queue.push(num);
                    queue.pop();
                }
            }
        }
        return queue.top();
    }


};