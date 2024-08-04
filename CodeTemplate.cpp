// //
// // Created by Younghusband on 2024/8/1.
// //
// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Solution {
// public:
//     vector<int> QuickSort(const vector<int> &numbers) {
//         vector<int> result;
//         result.push_back(numbers[0]);
//         int leftMax = numbers[0];
//         for (int i = 1; i < numbers.size(); i++) {
//             if (numbers[i] < result[result.size() - 1]) {
//                 while (numbers[i] < result[result.size() - 1] && !result.empty()) {
//                     result.pop_back();
//                 }
//             }
//             if (numbers[i] < leftMax) {
//                 continue;
//             }
//             leftMax = max(leftMax, numbers[i]);
//             result.push_back(numbers[i]);
//         }
//         return result;
//     }
//
// };
//
// inline int ReadInt() {
//     int number;
//     cin >> number;
//     return number;
// }
//
// template<typename T>
// inline vector<T> ReadVector(int size) {
//     vector<T> objects(size);
//     for (int i = 0; i < size; ++i) {
//         cin >> objects[i];
//     }
//     return objects;
// }
//
// template<typename T>
// inline void WriteVector(const vector<T> &objects, char delimeter = ' ') {
//     auto it = objects.begin();
//     if (it == objects.end()) {
//         return;
//     }
//     cout << *it;
//     for (++it; it != objects.end(); ++it) {
//         cout << delimeter << *it;
//     }
// }
//
// int main() {
//     int numbersNum = ReadInt();
//     vector<int> numbers = ReadVector<int>(numbersNum);
//     Solution solu;
//     auto res = solu.QuickSort(numbers);
//     cout << "[";
//     WriteVector(res, ' ');
//     cout << "]" << endl;
//     return 0;
// }
