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

using namespace std;

class TimerSystem {

        int curTime = 0;
        // 查询过期时间
        unordered_map<int, int> expMap;
        // 进度
        unordered_map<int, int> processMap;
        // 状态
        unordered_map<int, bool> stateMap;

public:
    TimerSystem(const vector<int>& timers)
    {
        for(int i = 0; i < timers.size(); i++) {
            expMap[i] = timers[i];
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
            if(!it->second) {
                it->second = true;
            }
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
                int timerTime = processMap[timerId]; // 当前计数器进度
                int exp = expMap[timerId] + curTime - timerTime; // 修正时差
                generate(timerId, curTime, exp, nowTime, res);
                timerTime += (nowTime - curTime); // 时间差
                processMap[timerId] = timerTime;
            }
        }
        // resort
        sort(res.begin(), res.end(), comparePairs);
        curTime = nowTime;
        return res;
    }

    void generate(int timerId, int cur, int round, int end, vector<pair<int, int>>& res) {
        for(int i = cur; i <= end; i++) {
            if(i != cur && i % round == 0) {
                res.push_back(make_pair(i, timerId));
            }
        }
    }

    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }

};