//
// Created by Younghusband on 2024/11/13.
//
#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:

    map<char, int> dic;
    map<int, char> redic;

    void createDic() {
        for(char c = 'A'; c <= 'Z'; c++) {
            int v = toascii(c) - 64;
            dic[c] = v;
            redic[v] = c;
        }
        for(char c = 'a'; c <= 'z'; c++) {
            int v = toascii(c) - 96;
            dic[c] = v;
            redic[v] = c;
        }
    }

    string SortLetterStr(const string& letterStr)
    {
        createDic();
        string tmp = letterStr;
        sort(tmp.begin(), tmp.end());
        string res = "";
        for(char c: tmp) {
            int v = dic[c];
            int y = (v * v) % 26 + 1;
            res += isupper(c) ? toupper(redic[y]) : redic[y];
        }
        return res;
    }
};

// int main () {
//
//     // char c = 'A';
//     //
//     cout << toascii('A') << endl;
//     cout << toascii('B') << endl;
//     cout << toascii('a') << endl;
//     cout << toascii('b') << endl;
//     //
//     // cout << pow(3, 2) << endl;
//     // Solution slo;
//     // string s = "abB";
//     // string res = slo.SortLetterStr(s);
//     // cout << res << endl;
//
// }