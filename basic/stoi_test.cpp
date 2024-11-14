// #include <iostream>
// #include <string>
//
// int main() {
//
//     // Binary to decimal
//     std::string binaryStr = "110101";  // Binary string
//     int binaryNum = std::stoi(binaryStr, nullptr, 2);
//     std::cout << "Binary: " << binaryStr << " converted to decimal: " << binaryNum << std::endl;
//
//     // Octal to decimal
//     std::string octalStr = "123";  // Octal string
//     int octalNum = std::stoi(octalStr, nullptr, 8);
//     std::cout << "Octal: " << octalStr << " converted to decimal: " << octalNum << std::endl;
//
//     // Decimal to decimal
//     std::string decimalStr = "456";  // Decimal string
//     int decimalNum = std::stoi(decimalStr, nullptr, 10);
//     std::cout << "Decimal: " << decimalStr << " converted to decimal: " << decimalNum << std::endl;
//
//     // Hexadecimal to decimal
//     std::string hexStr = "1A3F";  // Hexadecimal string
//     int hexNum = std::stoi(hexStr, nullptr, 16);
//     std::cout << "Hexadecimal: " << hexStr << " converted to decimal: " << hexNum << std::endl;
//
//     // Demonstration of handling invalid characters
//     std::string mixedStr = "123abc456";
//     size_t idx;  // Variable to store position of the first invalid character
//     try {
//         int mixedNum = std::stoi(mixedStr, &idx, 10);
//         std::cout << "Converted integer: " << mixedNum << std::endl;
//         std::cout << "Position of first unconvertible character: " << idx << std::endl;
//     } catch (const std::invalid_argument& e) {
//         std::cout << "Invalid input: " << e.what() << std::endl;
//     }
//
//     return 0;
// }
//
