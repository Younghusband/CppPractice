// #include <cstdio>
//
// int main() {
//
//     char s[100] = {0};
//
//     // 十进制输出
//     sprintf(s, "%d", 123);
//     printf("十进制输出: %s\n", s);  // 结果: "123"
//
//     // 指定宽度输出，左边补空格
//     sprintf(s, "%4d%4d", 123, 4567);
//     printf("指定宽度输出: %s\n", s);  // 结果: " 1234567"
//
//     // 八进制输出，宽度占8个位置
//     sprintf(s, "%8o", 123);
//     printf("八进制输出: %s\n", s);  // 结果: "      173" (173是123的八进制表示)
//
//     // 小写16进制，宽度占8个位置，右对齐
//     sprintf(s, "%8x", 4567);
//     printf("16进制输出: %s\n", s);  // 结果: "    11f7" (11f7是4567的十六进制表示)
//
//     // 输出浮点数，指定小数点后三位
//     sprintf(s, "%10.3f", 3.1415626);
//     printf("浮点数输出: %s\n", s);  // 结果: "    3.142"
//
//     // 注意: %.2f对于整数是不正确的
//     int i = 100;
//     sprintf(s, "%.2f", i);
//     printf("不正确的浮点数输出 (int): %s\n", s);  // 结果: "100.00"
//
//     // 正确的浮点数输出（将整数转换为 double）
//     sprintf(s, "%.2f", (double)i);
//     printf("正确的浮点数输出 (double): %s\n", s);  // 结果: "100.00"
//
//     return 0;
// }
