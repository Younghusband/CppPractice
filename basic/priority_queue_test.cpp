/**
 * Tips:
 * 1. operator() 的使用
 * 2. 遍历的时候一定切记要避免死循环
 */


#include <cmath>
#include <iostream>
#include <queue>


using namespace std;

struct Task {
    int priority;
    string name;
    Task(int p, string n) : priority(p), name(n) {}
};

struct Compare {
    bool operator()(const Task& a, const Task& b) {
        if(a.priority == b.priority)
            return a.name < b.name;
        return a.priority < b.priority;
    }
};

// int main() {
//
//     auto cmp = [](const int& p1, const int& p2) {
//         return p1 < p2;
//     };  // 这样是构造大根堆
//
//     // priority_queue<int> singleQ; // 默认大根
//     priority_queue<int, vector<int>, greater<int>> singleQ;  // 小根堆
//     priority_queue<int, vector<int>, decltype(cmp)> cQ(cmp);  // 也可以写个函数直接传函数名进来
//
//     singleQ.push(7);
//     singleQ.push(6);
//     singleQ.push(5);
//
//     while(!singleQ.empty()) {
//         cout << singleQ.top() << ", ";
//         singleQ.pop();
//     }
//     cout << endl;
//
//     // cQ.push(7);
//     // cQ.push(6);
//     // cQ.push(5);
//
//     auto cmp1 = [](const Task& a, const Task& b) {
//         if(a.priority == b.priority) {
//             return a.name > b.name;
//         }
//         return a.priority < b.priority;
//     };
//     // priority_queue<Task, vector<Task>, Compare> compareTaskPQ;
//     priority_queue<Task, vector<Task>, decltype(cmp1)> compareTaskPQ(cmp1);
//
//     compareTaskPQ.emplace(6, "an");
//     compareTaskPQ.push(Task(6, "fan"));
//     compareTaskPQ.emplace(1, "xi");
//     compareTaskPQ.emplace(3, "duan");
//     compareTaskPQ.emplace(4, "liu");
//
//     while(!compareTaskPQ.empty()) {
//         cout << compareTaskPQ.top().name << ": " << compareTaskPQ.top().priority;
//         compareTaskPQ.pop();
//         cout << ", ";
//     }
//     cout << endl;
//
// }
