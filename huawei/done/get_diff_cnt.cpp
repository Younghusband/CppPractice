//
// Created by Younghusband on 2024/10/10.
//


#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int GetDiffCnt(int diff, const vector<int>& numbers) {
        if(diff == 0) return 0;
        int cnt = 0;
        unordered_map<int, int> map;
        for(int num : numbers) {
            map[num] = num - diff;
        }
        for(int num : numbers) {
            int bu = map[num];
            if(map.find(bu) != map.end()) {
                cnt++;
            }

        }
        return cnt;
    }
};

