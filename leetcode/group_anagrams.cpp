//
// Created by Younghusband on 2024/8/7.
//


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // for std::sort

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    vector<vector<string>> res;
    for (const auto& item : strs) {
        // 创建一个可修改的字符串副本
        string sortedStr = item;
        // 对字符串进行排序
        sort(sortedStr.begin(), sortedStr.end());
        // 使用排序后的字符串作为 key
        map[sortedStr].push_back(item);
    }

    // 将分组结果放入结果向量中
    for (const auto& pair : map) {
        res.push_back(pair.second);
    }

    return res;
}

// int main() {
//     vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     vector<vector<string>> result = groupAnagrams(strs);
//     // 打印结果
//     for (const auto& group : result) {
//         for (const auto& str : group) {
//             cout << str << " ";
//         }
//         cout << endl;
//     }
//
//     return 0;
// }

