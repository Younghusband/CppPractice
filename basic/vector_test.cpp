//
// Created by Younghusband on 2024/8/6.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void print(vector<T>& arr) {
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

template <>
void print<string>(vector<string>& arr) {
    string res = "[";
    for (int i = 0; i < arr.size(); i++) {
        res += arr.at(i);  // 直接使用 string 类型
        if (i != arr.size() - 1) {
            res += ", ";
        }
    }
    res += "]";
    cout << res << endl;
}


bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    // 按照第一个值排序，第一个值相同则按照第二个值排序
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}


// int main() {
//     vector<int> vec = {1,2,3,4,5};
//     vec.erase(vec.begin());
//
//     vec.push_back(6);
//     print(vec);
//
//     swap(*vec.begin(), *vec.end());  // 等同于 swap(vec[0], vec[size - 1])
//     vec.insert(vec.begin() + 1, 99);
//     print(vec);
//     // for(auto it = vec.begin(); it != vec.end(); it++) {
//     //     cout << *it << " ";
//     // }
//     // cout << endl;
//     // for(auto it = vec.rbegin(); it != vec.rend(); it++) {
//     //     cout << *it << " ";
//     // }
//     reverse(vec.begin() + 1, vec.end() - 1);
//     cout << endl;
//     int valueToFind = 1;
//     auto it = find(vec.begin(), vec.end(), valueToFind);
//     if (it != vec.end()) {
//         cout << "Element found in vector." << endl;
//     } else {
//         cout << "Element not found in vector." << endl;
//     }
//     auto maxIt = max_element(vec.begin(), vec.end());
//     auto minIt = min_element(vec.begin(), vec.end());
//     cout << "max element is [" << *maxIt << "]" << endl;
//     cout << "min element is [" << *minIt << "]" << endl;
//
//     vector<int> rVec; // 倒序数组
//     rVec.assign(vec.rbegin(), vec.rend());
//     print(rVec);
//
//     // sort(rVec.begin(), rVec.end(), greater<int>());
//     sort(rVec.begin(), rVec.end(), [](auto& a, auto& b) {return a > b;} );
//     // sort(rVec.begin(), rVec.end(), [](auto& a, auto& b) -> bool {return a > b;} );
//     print(rVec);
//
//     rVec.emplace_back(100);
//     print(rVec);
//     rVec.emplace(rVec.begin(), -1);
//     print(rVec);
//
//     vector<pair<int, int>> needCompareVec = {
//         {3, 2},
//         {1, 4},
//         {2, 2},
//         {3, 1},
//         {1, 2}
//     };
//
//     // 使用自定义比较函数排序
//     sort(needCompareVec.begin(), needCompareVec.end(), comparePairs);
//     for (const auto& p : needCompareVec) {
//         cout << "(" << p.first << ", " << p.second << ")" << endl;
//     }
//
//     // test find and remove
//     vector<int> vec1 = {1, 1, 1, 10, 20, 30, 40, 50, 30};
//     auto it1 = find(vec1.begin(), vec1.end(), 30);
//     int index = distance(vec1.begin(), it1);
//     cout << "before remove:" << endl;
//     print(vec1);
//     cout << "find index = " << index << endl;
//     vec1.erase(it1);  // 根据迭代器删除
//     cout << "after remove:" << endl;
//     print(vec1);
//
//     vec1.push_back(1);
//     vec1.push_back(1);
//     vec1.push_back(1);
//     vec1.push_back(1);
//     vec1.push_back(1);
//
//     cout << "before execute \"remove\"" << endl;
//     print(vec1);
//     auto newEnd = remove(vec1.begin(), vec1.end(), 1);
//     cout << "after execute \"remove\"" << endl;
//     print(vec1);  // 会发现只是把元素全部移动到末尾
//     vec1.erase(newEnd, vec1.end());   // remove 需要搭配erase使用。不建议
//
//     cout << "after execute \"erase\"" << endl;
//     print(vec1);
//
//     vector<string> vec2 = {"a", "b", "abc"};
//     auto findIt = find(vec2.begin(), vec2.end(), "b");
//     cout << distance(vec2.begin(), findIt) << endl;
//
//     vector<string> strv = {"yyyy", "ffffffffff", "mmm"};
//     strv[0] += strv[1];
//     strv.erase(strv.begin() + 1);
//     print(strv);
//     cout << strv.back() << endl;
//
//     vector<string> newStrV = {"xxx", "6666"};
//     strv.insert(strv.end(), newStrV.begin(), newStrV.end());
//     print(strv);
//
// }


