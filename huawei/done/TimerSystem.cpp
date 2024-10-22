/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: 上机编程认证
 * Caution：本地调试时，只编译运行main.cpp文件，不要链接这个文件！因为本文件已经被main.cpp文件include了
 */

// done finished

#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class TimerSystem {

        int curTime = 0;
        // 每个计时器的
        map<int, int> expires;
        // 进度
        map<int, int> processMap;
        // 计时器状态
        map<int, bool> stateMap;

public:
    TimerSystem(const vector<int>& timers)
    {
        for(int i = 0; i < timers.size(); i++) {
            expires[i] = timers[i];
            processMap[i] = 0;
            stateMap[i] = false;
        }
    }

    bool TimerStart(int timerId)
    {
        auto it = stateMap.find(timerId);
        // 找到定时器
        if(it != stateMap.end()) {
            // 定时器关闭
            it->second = true;
            processMap[timerId] = 0; // 重置进度
            return true;
        }
        return false;
    }

    bool TimerStop(int timerId)
    {
        auto it = stateMap.find(timerId);
        // 定时器存在
        if(it != stateMap.end()) {
            it->second = false;
            return true;
        }
        return false;
    }

    vector<pair<int, int>> RunTimerSystem(int nowTime)
    {
        vector<pair<int, int>> res;
        // 遍历状态
        for(const auto& pair: stateMap) {
            int timerId = pair.first;
            bool state = pair.second;

            if(state) {
                int processedTime = processMap[timerId]; // 当前计数器进度
                int gap = curTime - processedTime; // 修正和时钟的差距
                int curStep = nowTime - curTime;
                generate(timerId, processedTime, processedTime + curStep, expires[timerId], res, gap);
                processedTime += curStep; // 本次行进时间
                processMap[timerId] = processedTime;
            }
        }
        // resort
        sort(res.begin(), res.end(), comparePairs);
        curTime = nowTime;
        return res;
    }

    void generate(int timerId, int begin, int end, int round, vector<pair<int, int>>& res, int clockGap) {
        for(int cur = begin + 1; cur <= end; cur++) {
            if(cur % round == 0) {
                res.push_back(make_pair(cur + clockGap, timerId));
            }
        }
    }

    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }

};

void print(vector<pair<int, int>>& data) {
    cout << "[";
    for(auto const& item: data) {
        cout << "[" << item.first << ", " << item.second << "]" << " ";
    }
    cout << "]" << endl;
}