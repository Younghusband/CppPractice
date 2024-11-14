//
// Created by Younghusband on 2024/8/4.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

void print(char str, char split);

void print(char str, char split) {
    cout << str << split;
}

#define XXX = "caonima";

vector<string> splitBySpace(const string& source) {
    stringstream ss(source);
    vector<string> res;
    string tmpword;
    while(ss >> tmpword) {
        res.push_back(tmpword);
    }
    return res;
}

template <typename T>
string vector2String(const vector<T>& vec) {
    ostringstream oss;
    oss << "[";
    for(size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if(i != vec.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
} // oss更适合只读，也更快

template <typename T>
string vector2String1(const vector<T>& vec) {
    stringstream ss;
    ss << "[";
    for(size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if(i != vec.size() - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
} // ss可读可输出

// int main() {
//     string spaceStr = "00 c1 0a 11 c9 45 77";
//     vector<string> ss = splitBySpace(spaceStr);
//     cout << vector2String1(ss) << endl;
//
//     string str = "Hello World!";
//     for(string::iterator it = str.begin(); it != str.end(); it++) {
//         print(*it, ' ');
//     }
//     cout << endl;
//     for(string::reverse_iterator it = str.rbegin(); it != str.rend(); it++) {
//         print(*it, ' ');
//     }
//     cout << endl;
//     string yf = "yang fan 110";
//     cout << yf.substr(1, 2) << endl;
//     cout << stoi(yf.substr(9)) << endl;
//
//     string str11("HelloWorld");
//     // str11.replace(1, 2, "yyds", 2, 3); // 使用yyds的子串（2,3）替换str1的子串（1， 2）
//     str11.replace(1,3,3,'S'); // 使用3个'S'字符替换str1的子串（1， 3）
//
//     cout << str11 << endl;
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
//     string newstr = hasStar.substr(0, hasStar.find_first_of("*"));
//     cout << newstr << endl;
//
//     if(hasNoStar == newstr) {
//         cout << "find!" << endl;
//     }
//
//     string str3("fuckyou");
//     cout << toupper(str3[0]) << endl; // 单个字符，小写 tolower
//
//     string str4;
//     for(size_t i = 0; i < str3.size(); i++) {
//         str4 += toupper(str3[i]);
//     }
//     cout << "转换为大写的 : " << str4 << endl;
//
//     // test transform
//     transform(str3.begin(), str3.end(), str3.begin(), ::tolower);
//     cout << "转换为小写的 : " << str3 << endl;
//
//     string readyToErase = "123454321";
//     cout << readyToErase.erase(4, 1) << endl;
//     cout << readyToErase.erase(4) << endl;  // 保留 下标0到3
//
//     string readyToInsert = "12344321";
//     readyToInsert.insert(4, 1, 'A');
//     cout << readyToInsert << endl;
//
//     string testsub = "xxx ssdf";
//     cout << testsub.substr(4, 4) << endl;
//
//     testsub.insert(testsub.begin(), 1, '0');
//     cout << testsub << endl;
// }




