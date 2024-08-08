//
// Created by Younghusband on 2024/8/8.
//
#include <cmath>
#include <list>
using namespace std;
class ScalingSys {
public:
    ScalingSys(int _capability) : capability(_capability) // 单机器处理能力
    {
        machineNum = 1; // 机器数量
        leftMessage = {}; // 消息队列
        currentTime = 0; // 当前时间
    }
    int JudgeWithMsgs(int time, int msgNum)
    {
        goToTime(time);
        leftMessage.emplace_back(make_pair(time, msgNum));
        int tmp = machineNum;
        int sum = 0, result = 1; // 最少需要一台机器，所以result初始化为1
        for (auto lt : leftMessage) { // 遍历消息队列，找出每条最少需要的机器数，取最大值
            sum += lt.second;
            int tmp1 = ceil(double(sum) / double((5 - time + lt.first) * capability));
            result = max(result, tmp1);
        }
        machineNum = result;
        return machineNum - tmp;
    }
    void goToTime(int time)
    {
        int tmp = 0; // 每次时间向前一步，如果消息处理能力大于队头，需要取出下一条继续处理
        while (!leftMessage.empty() && currentTime < time) { // 队列为空则不处理
            if (tmp) {
                if (tmp - leftMessage.front().second > 0) {
                    tmp -= leftMessage.front().second;
                    leftMessage.pop_front(); // 处理完毕出队
                } else {
                    leftMessage.front().second -= tmp;
                    tmp = 0; // 当前时间片处理能力耗尽后重置tmp
                    ++currentTime;
                }
            } else if (machineNum * capability - leftMessage.front().second > 0) {
                tmp = machineNum * capability - leftMessage.front().second;
                leftMessage.pop_front();
            } else {
                leftMessage.front().second -= machineNum * capability;
                ++currentTime;
            }
        }
        currentTime = time;
    }
private:
    int machineNum;
    int capability;
    int currentTime;
    list<pair<int, int>> leftMessage;
};