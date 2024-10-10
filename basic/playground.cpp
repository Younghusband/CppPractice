//
// Created by Younghusband on 2024/10/9.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sort(vector<int>& arr) {
    int len = arr.size();
    for(int i = 0; i < len - 1; i++) {
        bool hasSwap = false;
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                hasSwap = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if(!hasSwap) {
            break;
        }
    }
}

void print(const vector<int> arr) {
    string printRes = "[";
    int len = arr.size();
    if(len > 0) {
        for(int i = 0; i < len; i++) {
            printRes += to_string(arr[i]);
            if(i == len - 1) {
                printRes += "]";
            } else {
                printRes += ", ";
            }
        }
    }
    cout << printRes << endl;
}


// int main() {
//     vector<int> readyForSort = {4, 1, 2,3, 5, 8, -1};
//     sort(readyForSort);
//     print(readyForSort);
// }