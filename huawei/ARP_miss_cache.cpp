//
// Created by Younghusband on 2024/9/6.
//


#include <string>
#include <vector>

using namespace std;

class ArpSys {
public:
    ArpSys(int arpCap, int cachedPktCap, int perIpCap)
    {

    }

    vector<int> Update(int ip, const string& macAddr)
    {
        return {};
    }

    string Forward(int ip, int pktId)
    {
        return "";
    }
};