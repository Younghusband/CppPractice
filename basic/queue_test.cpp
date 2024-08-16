// //
// // Created by Younghusband on 2024/8/14.
// //
//
//
// int main() {
//
// priority_queue<int, deque<int>, greater<int>> prQue;
// vector<int> testData = {5, 6, 4};
// for (auto& num : testData) {
//     prQue.push(num); // 插入元素到队尾（并排序）
//     prQue.emplace(num); // 原地构造一个元素到队尾（并排序）
// }
// while (!prQue.empty()) {
//     cout << prQue.top() << endl; // 返回但不删除队首元素
//     prQue.pop(); // 删除队首元素
// }
// cout << prQue.size();
// // 对于tuple(pair)，优先比较第一个元素，然后依次比较
// priority_queue<tuple<int, int>> prQue1;
// prQue1.emplace(make_tuple(2, 5));
// prQue1.emplace(make_tuple(1, 3));
// prQue1.emplace(make_tuple(1, 2));
// while (!prQue1.empty()) {
//     cout << get<0>(prQue1.top()) << ", "<< get<1>(prQue1.top()) << endl; // 依次输出(2,5) (1,3) (1,2)
//     prQue1.pop();
// }
// // 自定义排序规则（这里是优先按照第二元素的小顶堆。也可以通过重载运算符和比较函数的方式，但还是推荐使用Lambda表达式的方式）
// //方法1：Lambda表达式
// auto cmp = [](const tuple<int, int>& a, const tuple<int, int>& b){return (get<1>(a) > get<1>(b));};
// priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)> prQue1(cmp);
// prQue1.emplace(make_tuple(2, 5));
// prQue1.emplace(make_tuple(0, 8));
// prQue1.emplace(make_tuple(3, 6));
// while (!prQue1.empty()) {
//     cout << get<0>(prQue1.top()) << ", "<< get<1>(prQue1.top()) << endl; // 依次输出(2,5) (3,6) (0,8)
//     prQue1.pop();
// }
// //方法2:重载运算符<
// struct cmp1
// {
//     tuple<int, int> value;
//     cmp1(tuple<int, int> val) : value(val) {
//
//     }
//     bool operator<(const cmp1& comp) const
//     {
//         return get<1>(value) > get<1>(comp.value);
//     }
// };
// int main()
// {
//     priority_queue<cmp1> prQue2;
//     prQue2.emplace(make_tuple(2, 5));
//     prQue2.emplace(make_tuple(0, 8));
//     prQue2.emplace(make_tuple(3, 6));
//     while (!prQue2.empty()) {
//         cout << get<0>(prQue2.top().value) << ", "<< get<1>(prQue2.top().value) << endl; // 依次输出(2,5) (3,6) (0,8)
//         prQue2.pop();
//     }
//     return 0;
// }
// //方法2:重写仿函数
// struct cmp1
// {
//     tuple<int, int> value;
//     cmp1(tuple<int, int> val) : value(val) {
//
//     }
//     // 重载仿函数，那么运算符重载就不需要了
//     // bool operator<(const cmp1& comp) const
//     // {
//     //     return get<1>(value) > get<1>(comp.value);
//     // }
// };
//
// struct cmp2
// {
//     bool operator() (cmp1 a, cmp1 b)
//     {
//         return get<1>(a.value) > get<1>(b.value);
//     }
// };
// int main()
// {
//     priority_queue<cmp1, vector<cmp1>, cmp2> prQue2;
//     prQue2.emplace(make_tuple(2, 5));
//     prQue2.emplace(make_tuple(0, 8));
//     prQue2.emplace(make_tuple(3, 6));
//     while (!prQue2.empty()) {
//         cout << get<0>(prQue2.top().value) << ", "<< get<1>(prQue2.top().value) << endl; // 依次输出(2,5) (3,6) (0,8)
//         prQue2.pop();
//     }
//     return 0;
// }
//
//
//
// }