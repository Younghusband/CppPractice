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

// int main() {
//     string str = "Hello World!";
//     cout << str.size() << endl;
//     cout << str.length() << endl;
//     for(string::iterator it = str.begin(); it != str.end(); it++) {
//         print(*it, ' ');
//     }
//     cout << endl;
//     for(size_t i = 0; i < str.size(); i++) {
//         print(str[i], ' ');
//     }
//     cout << endl;
//     for(char c : str) {
//         print(c, ' ');
//     }
//     cout << endl;
//     for(string::reverse_iterator it = str.rbegin(); it != str.rend(); it++) {
//         print(*it, ' ');
//     }
//     cout << endl;
//
//     string str1 = "Hello World!";
//     string str2 = "fuck you!";
//     cout << to_string(str1 == str) << endl;
//     cout << to_string(str1 == str2) << endl;
//
//     char charArray[] = "hello";
//     for(size_t i = 0; i < strlen(charArray); i++) {
//         cout << charArray[i] << ' ';
//     }
//     cout << endl;
//     std::cout << "Null terminator: " << static_cast<int>(charArray[5]) << endl;
// }




