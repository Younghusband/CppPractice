//
// Created by Younghusband on 2024/8/4.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void print(char str, char split);

void print(char str, char split) {
    cout << str << split;
}

#define XXX = "caonima";

// int main() {
//
//     // string str = "Hello World!";
//     // cout << str.size() << endl;
//     // cout << str.length() << endl;
//     // for(string::iterator it = str.begin(); it != str.end(); it++) {
//     //     print(*it, ' ');
//     // }
//     // cout << endl;
//     // for(size_t i = 0; i < str.size(); i++) {
//     //     print(str[i], ' ');
//     // }
//     // cout << endl;
//     // for(char c : str) {
//     //     print(c, ' ');
//     // }
//     // cout << endl;
//     // for(string::reverse_iterator it = str.rbegin(); it != str.rend(); it++) {
//     //     print(*it, ' ');
//     // }
//     // cout << endl;
//     //
//     // string str1 = "Hello World!";
//     // string str2 = "fuck you!";
//     // cout << to_string(str1 == str) << endl;
//     // cout << to_string(str1 == str2) << endl;
//     //
//     // char charArray[] = "hello";
//     // for(size_t i = 0; i < strlen(charArray); i++) { //
//     //     cout << charArray[i] << ' ';
//     // }
//     // cout << endl;
//     // std::cout << "Null terminator: " << static_cast<int>(charArray[5]) << endl;
//     //
//     // cout << "Test substr/stoi ..." << endl << endl;
//     // string yf = "yang fan 110";
//     // cout << yf.substr(1, 999) << endl;
//     // char c = yf.substr(1, 1)[0];
//     // cout << c << endl;
//     // cout << static_cast<int>(c) << endl;
//     // cout << stoi(yf.substr(9)) << endl;
//
//     string str11("HelloWorld");
//     // str11.replace(1, 2, "yyds", 2, 3); // 使用yyds的子串（2,3）替换str1的子串（1， 2）
//     str11.replace(1,3,3,'S'); // 使用3个'S'字符替换str1的子串（1， 3）
//
//     cout << str11 << endl;
//
//     string str111("HelloWorld");
//     size_t findPos = str111.find("ll");
//     if (findPos != string::npos) {
//         cout << str111.substr(findPos) << endl; // 打印输出lloWorld
//     }
//     findPos = str111.find('l', 5); // 从下标5开始查找
//     if (findPos != string::npos) {
//         cout << str111.substr(findPos) << endl; // 打印输出ld
//     }
//     findPos = str111.find_first_of("lol"); // 查找第一次出现字符'l'或'o'的位置
//     if (findPos != string::npos) {
//         cout << str111.substr(findPos) << endl; // 打印输出lloWorld（第一个'l'字符）
//     }
//
//     string hasStar = "111112*";
//     string hasNoStar = "111112";
//
//     string newstr = hasStar.substr(0, hasStar.find_first_of("*"));
//     cout << newstr << endl;
//
//     if(hasNoStar == newstr) {
//         cout << "find!" << endl;
//     }
//
//     string str3("fuckyou");
//     str3 += "x";
//     str3.append("C");
//     char c1 = 'a';
//     str3 += c1;
//     cout << str3 << endl;
//     str3 += toupper(c1);
//     cout << str3 << endl;
//
//     string readyToErase = "123454321";
//     cout << readyToErase.erase(4, 1) << endl;
//     cout << readyToErase.erase(4) << endl;  // 保留 下标0到3
//
//
//
//     string readyToInsert = "12344321";
//     readyToInsert.insert(4, 1, 'A');
//     cout << readyToInsert << endl;
//
//
// }




