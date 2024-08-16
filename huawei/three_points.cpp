#include <utility>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:

    int ajust(int p1, int p2) {
        int res;
        int left = min(p1, p2) - 1;
        int right = max(p1, p2) + 1;
        if(left >= 0) {
            res = left;
        } else {
            res = right > 18 ? -1 : right;
        }
        return res;
    }

    pair<int, int> ajust(int p1x, int p1y, int p2x, int p2y) {
        // TODO 尚未实现
    }

    pair<int, int> GetPoint(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        pair<int, int> res;
        int p1x = p1.first;
        int p1y = p1.second;
        int p2x = p2.first;
        int p2y = p2.second;
        // 先判断距离
        int xDistance = abs(p1x - p2x);
        int yDistance = abs(p1y - p2y);
        if(xDistance > 2 || yDistance > 2) {
            return {-1, -1};
        }
        int targetX;
        int targetY;
        // 同列
        if(p1x == p2x) {
            targetX = p1x;
            // 相邻
            if(yDistance == 1) {
                targetY = ajust(p1y, p2y);
            } else {
                targetY = (p1y + p2y) / 2;
            }
        }
        // 同行
        else if(p1y == p2y) {
            targetY = p1y;
            // 相邻
            if(xDistance == 1) {
                targetX = ajust(p1x, p2x);
            } else {
                targetX = (p1x + p2x) / 2;
            }
        }
        // 斜着
        else {
            if(xDistance != yDistance || (xDistance > 2 || yDistance > 2)) {
                return {-1, -1};
            }
            // 相邻
            if(xDistance == 1) {
                pair<int, int> ad = ajust(p1x, p1y, p2x, p2y);
                targetX = ad.first;
                targetY = ad.second;
            }
            // 间隔
            else {
                targetX = (p1x + p2x) / 2;
                targetY = (p1y + p2y) / 2;
            }
        }
        if(targetX < 0 || targetY < 0 || targetX > 18 || targetY > 18) {
            return {-1, -1};
        }
        return make_pair(targetX, targetY);
    }
};

// int main() {
//     Solution slo;
//     pair<int, int> res = slo.GetPoint(make_pair(18, 2), make_pair(17, 3));
//     cout << res.first << ", " << res.second << endl;
// }