
/**
 * 经验:
 *
 * vector使用下标方式塞值会有可能出现越界问题，需先规定好大小
 *
 */
#include <iostream>
#include <vector>

using namespace std;



unsigned int GetMinArea(int stopPoint, const vector<pair<int, int>> &operations)
{
    // 画图
    vector<pair<int, int>> xy(stopPoint + 1);
    int curX = 0;
    int curY = 0;
    for(const auto& item: operations) {
        int nextX = item.first;  // 1
        int nextY = curY + item.second;
        for(int i = curX; i <= nextX; i++) {
            xy[i] = make_pair(i, curY);
        }
        curX = nextX;
        curY = nextY;
    }
    if(curX < stopPoint) {
        for(int i = curX; i <= stopPoint; i++) {
            xy[i] = make_pair(i, curY);
        }
    }
    // 算面积
    int res = 0;
    for(int i = 1; i <= stopPoint; i++) {
        res += abs(xy[i - 1].second) * 1;
    }
    return res;
}

// int main()
// {
//     int num, stopPoint;
//     cin >> num >> stopPoint;
//
//     vector<pair<int, int>> operations;
//     for (int loop = 0; loop < num; loop++) {
//         int x, value;
//         cin >> x >> value;
//         operations.push_back(make_pair(x, value));
//     }
//
//     cout << GetMinArea(stopPoint, operations) << endl;
//     return 0;
// }