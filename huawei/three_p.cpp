//
// Created by Younghusband on 2024/10/30.
//
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:

    pair<int, int> findMid(const pair<int, int>& p1, const pair<int, int>& p2) {
        pair<int, int> res;
        int midx = (p1.first + p2.first) >> 1;
        int midy = (p1.second + p2.second) >> 1;
        res.first = midx;
        res.second = midy;
        return res;
    }

    pair<int, int> GetPoint(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        if(p1.first < 0 || p1.first > 18 || p2.first < 0 || p2.first > 18 || p1.second < 0 || p1.second > 18
            || p2.second < 0 || p2.first > 18) {
            return {-1, -1};
        }
        if(abs(p1.first - p2.first) > 2 || abs(p1.second - p2.second) > 2) {
            return {-1, -1};
        }
        pair<int, int> res;
        // 竖直
        if(p1.first == p2.first) {
            bool adj = (abs(p1.second - p2.second) == 1);
            // 相邻就延伸
            if(adj) {
                res.first = p1.first;
                int downp = p1.second < p2.second ? p1.second : p2.second;
                int topp = p1.second > p2.second ? p1.second : p2.second;
                // 触底取上
                if(downp == 0) {
                    res.second = topp + 1;
                } else {
                    res.second = downp - 1;
                }
                return res;
            }
            return findMid(p1, p2);
        }
        // 水平
        else if(p1.second == p2.second) {
            bool adj = (abs(p1.first - p2.first) == 1);
            // 相邻就延伸
            if(adj) {
                res.second = p1.second;
                int leftp = p1.first < p2.first ? p1.first : p2.first;
                int rightp = p1.first > p2.first ? p1.first : p2.first;
                // 触底取上
                if(leftp == 0) {
                    res.first = rightp + 1;
                } else {
                    res.first = leftp - 1;
                }
                return res;
            }
            return findMid(p1, p2);
        }
        // 斜  这里有误，默认45度了。。
        else {
            bool adj = (abs(p1.first - p2.first) == 1);
            // 不相邻不需要判断左右边界
            if(!adj) {
                return findMid(p1, p2);
            }
            pair<int,int> lp;
            pair<int,int> rp;
            lp = p1.first < p2.first ? p1 : p2;
            rp = lp == p1 ? p2 : p1;
            if(lp.first != 0) {
                res.first = lp.first - 1;
                res.second = lp.second - (rp.second - lp.second);
            }
            else {
                res.first = rp.first + 1;
                res.second = rp.second + (rp.second - lp.second);
            }
            // 右延伸
            if(res.first < 0 || res.second < 0) {
                return {-1, -1};
            }
            return res;
        }
    }

};


// int main() {
//     Solution slo;
//     pair<int, int> res = slo.GetPoint({18,1}, {17, 0});
//     cout << res.first << ", " << res.second << endl;
// }
