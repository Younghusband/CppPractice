#include <cmath>
#include <iostream>
#include <queue>


using namespace std;

// int main() {
//
//     auto comparator = [](const int& p1, const int& p2) {
//         return p1 < p2;
//     };  // 这样是构造大根堆
//
//     // priority_queue<int> singleQ; // 默认大根
//     priority_queue<int, vector<int>, greater<int>> singleQ;  // 小根堆
//     priority_queue<int, vector<int>, decltype(comparator)> cQ(comparator);
//
//
//     singleQ.push(7);
//     singleQ.push(6);
//     singleQ.push(5);
//
//     // while(!singleQ.empty()) {
//     //     cout << singleQ.top() << ", ";
//     //     singleQ.pop();
//     // }
//     // cout << endl;
//
//
//     cQ.push(7);
//     cQ.push(6);
//     cQ.push(5);
//
//
// }
