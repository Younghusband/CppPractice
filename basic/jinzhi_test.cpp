// //
// // Created by Younghusband on 2024/10/23.
// //
//
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 2 to 10
string binary_2_int(const string& bstr) {
    int res = 0;
    for(char c: bstr) {
        res = res * 2 + (c - '0');
    }
    return to_string(res);
}

string int_2_binary(const string& istr) {
    int srci = stoi(istr);
    if(srci == 0) return "0";
    string res = "";
    while(srci > 0) {
        res = to_string(srci % 2) + res;
        srci /= 2;
    }
    return res;
}

// int main() {
//
//     cout << "35 de 8: " << std::oct << 35<< endl;
//     cout << "35 de 10: " << std::dec << 35 << endl;
//     cout << "35 de 16: " << std::hex << 35 << endl;
//     cout << "35 de 2: " << bitset<8>(35) << endl;
//
//     // string hexStr = "1A3F";
//     string hexStr1 = "c0";
//     int ten_jin1 = stoi(hexStr1, nullptr, 16); // 16 -> 10
//     cout << ten_jin1 << endl;
//
//     // 16 to 10
//     int hexValue = 0x1F;
//     cout << "hexValue's decimal :" << hexValue << endl;
//     hexValue++;
//     cout << "after ++ :" << hexValue << endl;
//
//     // 10 to 16
//     string n_str1 = "12345";
//     int decStr = stoi(n_str1);
//     cout << "Decimal n is Hex: " << hex << decStr << endl;
//     stringstream ss;
//     ss << hex << decStr;
//     cout << "Decimal by ss transfer: " << ss.str() << endl;
//     int n = stoi(n_str1);
//     cout << n + 1 << endl;
//
//     // 16 to 2
//
//     // 2 to 16
//
//     // 2 to 10
//     cout << binary_2_int("110") << endl;
//
//
//     // 10 to 2
//     cout << int_2_binary("8") << endl;
//
//     int n1 = 53;
//     std::bitset<32> bin(n1);
//     std::cout << "10 jinzhi: " << n1 << " transfer 2 jinzhi: " << bin << std::endl;
//
//     // ss usage
//     string cp_str = "12345 11.11 0";
//     int intVal;
//     float floatVal;
//     bool boolVal;
//     stringstream ss1(cp_str);
//     ss1 >> intVal >> floatVal >> boolVal;
//
//     if(!ss1.fail()) {
//         cout << "Integer: " << intVal << endl;
//         cout << "Float: " << floatVal << endl;
//         cout << "Boolean: " << boolalpha << boolVal << endl;
//     } else {
//         cout << "Conversion failed!" << endl;
//     }
//
//     string bin_str = "110101 0110 10";
//     bitset<8> b1;
//     bitset<8> b2;
//     bitset<8> b3;
//     stringstream ssb(bin_str);
//     ssb >> b1 >> b2 >> b3;
//     if(ssb.fail()) {
//         cout << "ssb Conversion failed..." << endl;
//     } else {
//         cout << "b1: " << b1.to_string() << endl;
//         cout << "b2: " << b2.to_string() << endl;
//         cout << "b3: " << b3.to_string() << endl;
//         cout << "===========================" << endl;
//     }
//
//     return 0;
// }

