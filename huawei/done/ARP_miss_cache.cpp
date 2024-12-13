//
// Created by Younghusband on 2024/9/6.
//


#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ArpSys {

public:
    int ipMaxSize;
    int deviceMaxMsgSize;
    int ipMaxMsgSize;  // <= deviceMaxMsgSize

    // 用于淘汰表项
    list<pair<int, string>> ipMacData;  // ip : mac
    unordered_map<int, list<pair<int, string>>::iterator> ipMacCache;

    // 报文相关
    unordered_map<int, vector<int>> ipPktMap;
    int totalPktCnt = 0;

    ArpSys(int arpCap, int cachedPktCap, int perIpCap)
    {
        ipMaxSize = arpCap;               // 总ip mac对
        deviceMaxMsgSize = cachedPktCap;  // 设备总报文数
        ipMaxMsgSize = perIpCap;          // 每个ip最大报文数
    }

    vector<int> Update(int ip, const string& macAddr)
    {
        // 存在该ip的映射关系
        if(ipMacCache.find(ip) != ipMacCache.end()) {
            ipMacData.splice(ipMacData.begin(), ipMacData, ipMacCache[ip]); // 这里应该算命中
            ipMacCache[ip]->second = macAddr;
            return {};
        }
        // 表项已满
        if(ipMacData.size() == ipMaxSize) {
            ipMacCache.erase(ipMacData.back().first);
            ipMacData.pop_back();
        }
        ipMacData.emplace_front(ip, macAddr);
        ipMacCache[ip] = ipMacData.begin();
        // 发送
        vector<int> pkts = sendPkt(ip);
        totalPktCnt -= pkts.size();
        return pkts;
    }

    string Forward(int ip, int pktId)
    {
        // 找到ip->mac
        if(ipMacCache.find(ip) != ipMacCache.end()) {
            ipMacData.splice(ipMacData.begin(), ipMacData, ipMacCache[ip]); // 这里应该算命中
            return ipMacCache[ip]->second;
        }
        // 找不到
        if (totalPktCnt >= deviceMaxMsgSize || ipPktMap[ip].size() >= ipMaxMsgSize) {
            return "";  // 超出缓存限制，无法缓存
        }
        totalPktCnt++;
        ipPktMap[ip].push_back(pktId);
        return "";
    }

    vector<int> sendPkt(int ip) {
        vector<int> pkts = ipPktMap[ip];
        if(pkts.size() > 0) {
            sort(pkts.begin(), pkts.end());
            ipPktMap.erase(ip);
            return pkts;
        } else {
            return {};
        }
    }

};

