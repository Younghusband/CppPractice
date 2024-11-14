// #include <iostream>
// #include <queue>
//
// using namespace std;
//
// int main() {
//     queue<int> q({1, 2, 3});
//
//     q.push(4);
//     q.push(5);
//
//     cout << "Queue elements after pushing 4 and 5:" << endl;
//
//     while(!q.empty()) {
//         auto item = q.front();
//         cout << item << endl;
//         q.pop();
//     }
//
//     cout << "Queue is now empty!" << endl;
//
//     queue<int> newQueue;
//     newQueue.push(10);
//     newQueue.push(20);
//     newQueue.push(30);
//
//     cout << "Front element of the new queue: " << newQueue.front() << endl;
//     cout << "Back element of the new queue: " << newQueue.back() << endl;
//
//     newQueue.pop();
//     cout << "After popping, front element of the new queue: " << newQueue.front() << endl;
//
//     cout << "Size of the new queue after one pop: " << newQueue.size() << endl;
//
//     if (newQueue.empty()) {
//         cout << "Queue is empty!" << endl;
//     } else {
//         cout << "Queue is not empty!" << endl;
//     }
//
//     return 0;
// }
