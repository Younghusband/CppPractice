//
// Created by Younghusband on 2024/8/16.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
// TODO 研究稳定排序问题
bool comparePair(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
};

void print(const vector<pair<int, int>> vec) {
    for(auto const& item: vec) {
        cout << item.first << ", " << item.second << endl;
    }
}


// int main() {
//     vector<pair<int, int>> vp = {
//         {0, 5}, {5, 8}, {10, 6}, {2, 11}, {2, 3}, {5, 1}
//     };
//     // sort(vp.begin(), vp.end());
//     sort(vp.begin(), vp.end(), comparePair);
//     // sort(vp.begin(), vp.end());
//     print(vp);
// }
