//
// Created by Younghusband on 2024/8/13.
//


#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;


template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}


// int main() {
//
//     cout << to_string(add(3 , 0.5)) << endl;
//
//     pair<int, int> xxx;
//     xxx = make_pair(1, 2);
//     cout << xxx.first << ", " << xxx.second << endl;
//
//     vector<int> nums = {3,1,4,1,5,9};
//     sort(nums.begin(), nums.end(), greater<int>());
//     for(const auto& num : nums) {
//         std::cout << num << ' ';
//     }
//     cout << endl;
//     sort(nums.begin(), nums.end());
//     for(const auto& num : nums) {
//         std::cout << num << ' ';
//     }
//
//     // 找到第三小的元素
//     nth_element(nums.begin(), nums.begin() + 2, nums.end());
//     cout << endl << "The third smallest element is: " << nums[2] << endl;
//     cout << "Partial sorted range: ";
//     for(int num: nums) {
//         cout << num << " ";
//     }
//     cout << endl;
//
//     char s[100]={0};
//     sprintf(s, "%d", 123); //十进制输出产生"123"
//     sprintf(s, "%4d%4d", 123, 4567); //指定宽度不足的左边补空格，产生：" 1234567"
//     sprintf(s, "%8o", 123);	//八进制输出，宽度占8个位置
//     sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
//     sprintf(s, "%10.3f", 3.1415626); //产生：" 3.142"
//     // cout << s << endl;
//     int i = 100;
//     sprintf(s, "%.2f", (float)i);	//注意这是不对的
//
//     vector<tuple<int, string, int>> forAnyTest;
//     forAnyTest.push_back(make_tuple(1, "xxx", 0));
//     forAnyTest.push_back(make_tuple(1, "xxx1", 10));
//     forAnyTest.push_back(make_tuple(1, "xxx2", 20));
//
//     bool has = any_of(forAnyTest.begin(), forAnyTest.end(), [](auto && item) {return get<2>(item) == 0;} );
//
//     cout << has << endl;
//
// }

