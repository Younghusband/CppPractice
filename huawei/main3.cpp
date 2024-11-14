/*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: 上机编程认证
 * Caution：本地调试时，只编译运行main.cpp文件，不要链接这个文件！因为本文件已经被main.cpp文件include了
 *
* 某网络设备持续的监控经过该设备的激据流量，每秒统计一次，统计结果保存在traffics 数组中
如果某段连续的 「时间窗口] window 中 ( minLen <= window.length <=maxLen ： minLen 和 maxLen 由用户指定) 。 流量之和大于用户给定的 threshold值，则设备会上报一个流量越限事件。
注：只要两个时间窗口的起点和终点位置中任一个不同，就视为不同的时间窗口。
请根据给出的 traffics 数组及 minLen、 maxLen、threshold 参数, 计算流量越限事件的个数
 */

#include <vector>

using namespace std;

class Solution {
public:
    int GetEventCount(const vector<int>& traffics, int minLen, int maxLen, int threshold)
    {
        return 0;
    }
};