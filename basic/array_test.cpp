//
// Created by Younghusband on 2024/8/6.
//

#include <iostream>
#include <array>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

using namespace std;

// int main() {
//
//     int cArr[] = {1,2,3,4,5};
//     for(int i : cArr) {
//         cout << i << ' ';
//     }
//     cout << endl;
//     int size = sizeof(cArr) / sizeof(cArr[0]);
//     for(size_t i = 0; i < size; i++) {
//         cout << cArr[i] << ' ';
//     }
//     cout << endl;
//     array arr = {6, 7, 8, 9, 10};
//     for(int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;
//     // for(int* it = begin(cArr); it != end(cArr); it++) {
//     //     cout << *it << " ";
//     // }
//     swap(arr[0], arr[4]);
//     for(int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;
//
//     int hsize = ARRAY_SIZE(arr);
//     cout << hsize << endl;
//
// }
