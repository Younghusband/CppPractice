//
// Created by Younghusband on 2024/8/13.
//

#include <cmath>
#include <iostream>
#include <list>
using namespace std;

void print(const list<int>& data) {
    for(auto const num: data) {
        cout << num << endl;
    }
    cout << "----------------------" << endl;
}

void print(const list<pair<int, string>>& data) {
    for(auto const item: data) {
        cout << item.first << ", " << item.second << endl;
    }
    cout << "----------------------" << endl;
}


// int main() {
//
//     list<pair<int, string>> data = {{1, "yangfan"}, {2, "xuxiaorong"}, {3, "heyu"}};
//     data.splice(data.begin(), data, next(next(data.begin())));  // 适用于已有数据的腾挪
//     print(data);
//
//     list<int> singleList;
//
//     singleList.push_front(1);
//     singleList.push_front(2);
//     print(singleList); // 2 1
//
//     singleList.push_back(3);
//     singleList.push_back(4);
//
//     print(singleList);
//     // singleList.splice(singleList.begin(), singleList, 100);  // 无法这样插入
//
//     singleList.insert(next(singleList.begin()), 100);
//     print(singleList);
//
//     list<int> newList({7, 8, 9});
//     singleList.splice(singleList.end(), newList);
//     print(singleList);
//     print(newList);  // newlist为空
//
//     list<int> newList1({10, 11, 12});
//     singleList.insert(singleList.begin(), newList1.begin(), newList1.end());
//     print(singleList);
//     print(newList1);
//
//     singleList.pop_back();
//     singleList.pop_front();
//     cout << singleList.back() << endl << "----------------------" << endl; // 注意 begin end是iterator  front back是实际引用
//
// }
