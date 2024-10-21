//
// Created by Younghusband on 2024/9/6.
//


#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ArpSys {

private:
    int ipMaxSize;
    int deviceMaxMsgSize;
    int ipMaxMsgSize;  // <= deviceMaxMsgSize

    // unordered_map<int, string> ipMacMap;
    // 用于淘汰表项
    list<pair<int, string>> ipMacData;  // ip : mac
    unordered_map<int, list<pair<int, string>>::iterator> ipMacCache;

    // 报文相关
    unordered_map<int, vector<int>> ipPktMap;

public:
    ArpSys(int arpCap, int cachedPktCap, int perIpCap)
    {
        ipMaxSize = arpCap;
        deviceMaxMsgSize = cachedPktCap;
        ipMaxMsgSize = perIpCap;
    }

    vector<int> Update(int ip, const string& macAddr)
    {
        // 存在该ip的映射关系
        if(ipMacCache.find(ip) != ipMacCache.end()) {
            ipMacCache[ip]->second = macAddr;
            return {};
        }
        if(ip)


        return {};
    }

    string Forward(int ip, int pktId)
    {
        return "";
    }
};