//
// Created by Younghusband on 2024/10/24.
//
#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * "45 00 10 3c 7c 48 20 03 80 06 00 00 c0 a8 01 02 c0 a8 14 b8"
 * "4156,1,192.168.20.184"
 *
 * "45 00 00 ff 7c 48 b0 03 80 06 00 00 00 a8 01 02 c0 a8 00 b8"
 * "255,5,192.168.0.184"
 */
class Solution {
public:

    string hex2binary(const string& hexStr) {
        unordered_map<char, string> h2b = {
            {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
        };

        string res = "";
        for(char c: hexStr) {
            res += h2b[toupper(c)];
        }
        return res;
    }

    string binary2(const string& bstr) {
        int res = 0;
        for(int i = bstr.size() - 1; i >= 0; i--) {
            if(bstr[i] == '1') {
                res += pow(2, bstr.size() - 1 - i);
            }
        }
        return to_string(res);
    }

    string GetData(const string& data)
    {
        string res = "";
        // 1. len
        int len = stoi(data.substr(6, 2) + data.substr(9, 2), nullptr, 16);
        string lenstr = to_string(len);

        res += lenstr;
        res += ",";
        // 2. mark
        string markStr = binary2(hex2binary(data.substr(18, 2)).substr(0, 3));

        res += markStr;
        res += ",";
        // 3. target address

        string address1 = to_string(stoi(data.substr(48, 2), nullptr, 16));
        string address2 = to_string(stoi(data.substr(51, 2), nullptr, 16));
        string address3 = to_string(stoi(data.substr(54, 2), nullptr, 16));
        string address4 = to_string(stoi(data.substr(57, 2), nullptr, 16));

        res += address1;
        res += ".";
        res += address2;
        res += ".";
        res += address3;
        res += ".";
        res += address4;

        return res;
    }
};

// int main() {
//     Solution slo;
//     slo.GetData("45 00 10 3c 7c 48 20 03 80 06 00 00 c0 a8 01 02 c0 a8 14 b8");
// }