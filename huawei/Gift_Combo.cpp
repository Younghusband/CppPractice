//
// Created by Younghusband on 2024/9/5.
//

#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> GetTopTPack(const vector<int>& goodsPrice, const vector<int>& fruitsPrice, int num) {
       vector<pair<int, int>> tmp;
       auto comparator = [](const pair<int, int>& p1, const pair<int, int>& p2) {
           int p1Sum = p1.first + p1.second;
           int p2Sum = p2.first + p2.second;
           if(p1Sum == p2Sum)
               return p1.first < p2.first;  // 大根堆
           return p1Sum < p2Sum;
       };
        // auto comparator = [](const pair<int, int>& p1, const pair<int, int>& p2) {
        //     return (p1.first + p1.second) > (p2.first + p2.second);
        // };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for(int goodP: goodsPrice) {
            for(int fruitP: fruitsPrice) {
                if(pq.size() < num) {
                    pq.push(make_pair(goodP, fruitP));
                } else {
                    pair<int, int> curMax = pq.top();
                    int curSum = goodP + fruitP;
                    int heapTop = curMax.first + curMax.second;
                    // 小于堆顶，要进入堆
                    if(curSum <= heapTop) {
                        // pq.
                        pq.push(make_pair(goodP, fruitP));
                        pq.pop();
                    }
                }
            }
        }

        while(!pq.empty()) {
            pair<int, int> curP = pq.top();
            tmp.push_back(curP);
            pq.pop();
        }

        sort(tmp.begin(), tmp.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            int p1Sum = p1.first + p1.second;
            int p2Sum = p2.first + p2.second;
            if(p1Sum == p2Sum) {
              return p1.first < p2.first;
            }
            return p1Sum < p2Sum;
        });
        return vector<pair<int, int>>(tmp.begin(), tmp.begin() + num);
    }
};

// int main() {
//     Solution slo;
//     // [170, 100, 140, 150, 130, 125, 120, 110]
//     // [55,50,80,60,65,45]
//     // 10
//     vector<int> goods = {170, 100, 140, 150, 130, 125, 120, 110};
//     vector<int> prices = {55,50,80,60,65,45};
//
//     vector<pair<int,int>> res = slo.GetTopTPack(goods, prices, 10);
//     for(const auto& item: res) {
//         cout << item.first << ", " << item.second << endl;
//     }
//
// }



