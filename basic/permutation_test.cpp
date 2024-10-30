//
// Created by Younghusband on 2024/10/18.
//

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


// int main() {
//     std::string str("HelloWorld");
//     auto itr = find(str.begin(), str.end(), 'o');
//     if (itr != str.end()) {
//         cout << itr - str.begin() << endl; // 输出4
//     }
//     sort(str.begin(), str.end());
//     cout << str << endl; // 输出排序结果HWdellloor
//     str.assign("HelloWorld");
//     cout << str << endl;
//     reverse(str.begin(), str.end());
//     cout << str << endl; // 输出反转结果dlroWolleH
//     // abc按照字典序排序分别为：abc，acb，bac，bca，cab，cba
//     str.assign("abc");
//     next_permutation(str.begin(), str.end()); // 输出字典序全排列的下一个排列acb
//     cout << str << endl;
//     str.assign("cba");
//     prev_permutation(str.begin(), str.end()); // 输出字典序全排列的上一个排列cab
//     cout << str << endl;
//
//     str.assign("cba"); // 已经是最大排列
//     // 达到最大排列的时候，返回值会是false，但实际会执行到下一个排列即最小排列
//     if(next_permutation(str.begin(), str.end())) {
//         cout << "虽然但是，还能下一个" << endl;
//     }
//     cout << str << endl;
// }
