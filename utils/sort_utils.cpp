//
// Created by Younghusband on 2024/7/31.
//

#include <iostream>
#include "sort_utils.h"
#include <algorithm>

namespace sort_utils {

    using namespace std;

    void bubble_sort(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++) {
            bool hasSwap = false;
            for(int j = 0; j < arr.size() - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    hasSwap = true;
                }
            }
            if(!hasSwap) {
                break;
            }
        }
    }

}
