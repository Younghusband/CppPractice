//
// Created by Younghusband on 2024/8/4.
//
// char buf[32] = {0};
// string result;
// string input;
// cin >> input;
// uint8_t* ptr = reinterpret_cast<uint8_t* >(&input);

// sprintf(buf, "%02X %02X %02X %02X\n", ptr[3], ptr[2], ptr[1], ptr[0]);
// result += buf;
// sprintf(buf, "%02X %02X %02X %02X", ptr[0], ptr[1], ptr[2], ptr[3]);
// result += buf;
// cout << result << endl;

#include <bitset>
#include <string>
#include <iostream>
#include <vector>


using namespace std;
int main() {
    // string result;
    // char buf[100]={0};
    // sprintf(buf, "%d", 123); //十进制输出产生"123"
    // cout << buf << endl;
    // sprintf(buf, "%4d%4d", 123, 4567); //指定宽度不足的左边补空格，产生：" 1234567"
    // cout << buf << endl;
    // sprintf(buf, "%8o", 123);	//八进制输出，宽度占8个位置
    // cout << buf << endl;
    // sprintf(buf, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
    // cout << buf << endl;
    // sprintf(buf, "%10.3f", 3.1415626); //产生：" 3.142"
    // cout << buf << endl;
    // int i = 100;
    // sprintf(buf, "%.2f", i);	//注意这是不对的
    // cout << buf << endl;
    // sprintf(buf, "%.2f", (double)i);	//要按照这种方式才行
    // cout << buf << endl;

    // cout << "35的8进制:" << oct << 35<< endl;
    // cout << "35的10进制" << dec << 35 << endl;
    // cout << "35的16进制:" << hex << 35 << endl;
    // cout << "35的2进制: " << bitset<8>(35) << endl;      //<8>：表示保留8位输出
    // cout << "呵呵哈哈哈或" << endl;

    vector<int> intVector = {1, 1, 3, 3, 5};
    oddTimesNumber(intVector);

    return 0;

}


// 偶数次的数字与自身异或为0，因此最后的结果必定是奇数次的数字本身
// 时间复杂度：O(n)

int oddTimesNumber(vector<int> nums) {
    int result = 0;
    for (auto &num : nums) {
        result ^= num;
    }
    return result;
}
