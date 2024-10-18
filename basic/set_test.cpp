//
// Created by Younghusband on 2024/9/13.
//


#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

// int main() {
//
//     set<string> strSet;
//     strSet.insert("xxx");
//     cout << strSet.contains("xxx") << endl;
//
//     set<int> intSet;
//     auto res1 = intSet.insert(10);
//     cout << res1.second << endl;
//     auto res2 = intSet.insert(10);
//     cout << res2.second << endl;
//     auto it = intSet.find(20);
//     if(it == intSet.end()) {
//         cout << "cant find" << endl;
//     }
//
//     if(intSet.count(20) == 0) {
//         cout << "count zero" << endl;
//     }
//
//     intSet.insert(20);
//
//     if(intSet.find(20) != intSet.end()) {
//         cout << "find !" << endl;
//     }
//
//     // cout << intSet.contains(20) << endl;
//
//     intSet.erase(20);
//     cout << intSet.size() << endl;
//
//     set<int> ordered_set;
//     ordered_set.insert(5);
//     ordered_set.insert(2);
//     ordered_set.insert(8);
//     cout << "std::set elements:";
//     for (auto& elem : ordered_set) {
//         cout << " " << elem;
//     }
//     cout << endl;
//
//     // 使用 std::unordered_set
//     unordered_set<int> unordered_set;
//     unordered_set.insert(5);
//     unordered_set.insert(2);
//     unordered_set.insert(8);
//     std::cout << "std::unordered_set elements:";
//     for (auto& elem : unordered_set) {
//         std::cout << " " << elem;
//     }
//     std::cout << std::endl;
//
// }
