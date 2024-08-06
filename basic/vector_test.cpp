//
// Created by Younghusband on 2024/8/6.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(vector<int>& arr) {
    string res = "[";
    for(int i = 0; i < arr.size(); i++) {
        res += to_string(arr.at(i));
        if(i != arr.size() - 1) {
            res += ", ";
        }
    }
    res += "]";
    cout << res << endl;
}

// int main() {
//     vector<int> vec = {1,2,3,4,5};
//     size_t size = vec.size();
//     // cout << size << endl;
//     vec.push_back(6);
//     // cout << vec.size() << endl;
//     print(vec);
//     vec.insert(vec.begin() + 1, 99);
//     print(vec);
//     for(auto it = vec.begin(); it != vec.end(); it++) {
//         cout << *it << " ";
//     }
//     cout << endl;
//     for(auto it = vec.rbegin(); it != vec.rend(); it++) {
//         cout << *it << " ";
//     }
//     cout << endl;
//     vector<int> rVec; // 倒序数组
//     rVec.assign(vec.rbegin(), vec.rend());
//     print(rVec);
//     // sort(vec.begin, vec.end());
//     // print(vec);
//
//     sort(rVec.begin(), rVec.end());
//     print(rVec);
// }
