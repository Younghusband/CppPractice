//
// Created by Younghusband on 2024/7/31.
//

#include <iostream>
#include "sort_utils.h"

namespace sort_utils {

    using namespace std;

    void bubble_sort(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            // 元素少一轮
            bool hasSwap = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    hasSwap = true;
                }
            }
            if (!hasSwap) break;
        }
    }

    void printArray(const vector<int> &arr) {
        for (int num: arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

}
