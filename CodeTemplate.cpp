// //
// // Created by Younghusband on 2024/8/1.
// //
// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Solution {
// public:
//     // 待实现函数，在此函数中填入答题代码;
//     vector<int> QuickSort(const vector<int>& numbers)
//     {
//         vector<int> result;
//         return result;
//     }
// };
//
// inline int ReadInt()
// {
//     int number;
//     cin >> number;
//     return number;
// }
//
// template<typename T>
// inline vector<T> ReadVector(int size)
// {
//     vector<T> objects(size);
//     for (int i = 0; i < size; ++i) {
//         cin >> objects[i];
//     }
//     return objects;
// }
//
// template <typename T> inline void WriteVector(const vector<T> &objects, char delimeter = ' ')
// {
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
// int main()
// {
//     int numbersNum = ReadInt();
//     vector<int> numbers = ReadVector<int>(numbersNum);
//     Solution solu;
//     auto res = solu.QuickSort(numbers);
//     cout << "[";
//     WriteVector(res, ' ');
//     cout << "]" << endl;
//     return 0;
// }