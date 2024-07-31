//
// Created by y30064873 on 2024/7/31.
//

#include "huawei/Solution.h";
#include <cmath>
#include <cstdio>

using namespace std;

string Solution::GetHexString(long long input)
{
    if (input > pow(2, 32) || input < -pow(2, 31)) {
        return "overflow";
    }
    string result;
    char buf[32] = {0};
    uint8_t *ptr = reinterpret_cast<uint8_t *>(&input);
    sprintf_s(buf, 32, "%02X %02X %02X %02X\n", ptr[3], ptr[2], ptr[1], ptr[0]);
    result += std::string(buf);
    sprintf_s(buf, 32, "%02X %02X %02X %02X", ptr[0], ptr[1], ptr[2], ptr[3]);
    result += std::string(buf);
    return result;
}
