#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>


/**
 * 大概率考试当时的编译问题是由于struct的构造缺失等原因导致的
 *
 *
 */

using namespace std;
struct Proc {
    int procId;
    int leftMem;
    vector<pair<int, int>> data; // device -> memCost

    // 带参构造
    Proc(int id, int mem, const vector<pair<int, int>>& d)
        : procId(id), leftMem(mem), data(d) {}
};

struct Group {
    vector<Proc> data;

    Group() = default;
    Group(const vector<Proc>& p) : data(p) {}

};

class DeviceMgtSystem {

public:
    const int TYPE_NUM = 3;
    // pid, leftmem, data: device /mem
    unordered_map<int, Group> totalData;
    int maxmem;

    unordered_map<int, string> deviceAddr;

    vector<Proc> createProcs(int procNum, int maxMem) {
        vector<Proc> res;
        vector<pair<int, int>> v;
        for(int i = 0; i < procNum; i++) {
            Proc p(i, maxmem, v);
            res.push_back(p);
        }
        return res;
    }

    int loadBalance(vector<Proc> data) {
        auto cmp = [](const Proc& p1, const Proc& p2) {
            int p1m = p1.leftMem;
            int p2m = p2.leftMem;
            int p1d = p1.procId;
            int p2d = p2.procId;
            if(p1m == p2m) {
                return p1d < p2d;
            }
            return p1m > p2m;
        };
        sort(data.begin(), data.end(), cmp);
        return data[0].procId;
    }

    pair<int, int> decodeDeviceAddr(const string& addr) {
        pair<int, int> res;
        stringstream ss(addr);
        int tmpw;
        ss >> tmpw;
        res.first = tmpw;

        ss >> tmpw;
        res.second = tmpw;
        return res;
    }

    DeviceMgtSystem(int procNum, int maxMemSize) {
        maxmem = maxMemSize;
        for(int i = 1; i <= TYPE_NUM; i++) {
            Group g(createProcs(procNum, maxMemSize));
            totalData[i] = g;
        }
    }

    int CreateDevice(int deviceId, int deviceType, int memSize)
    {
        // by type find group
        // get procId
        vector<Proc>& data = totalData[deviceType].data;
        int pId = loadBalance(data);
        Proc& p = data.at(pId);
        int & mem = p.leftMem;
        if(mem < memSize) {
            return -1;
        }
        mem -= memSize;
        p.data.push_back(make_pair(deviceId, memSize));
        string addr = "";
        addr += to_string(deviceType);
        addr += " ";
        addr += to_string(pId);
        deviceAddr[deviceId] = addr;
        return pId;
    }

    void releaseDeviceMem(int gId, int pId, int dId) {
        Proc& p = totalData[gId].data.at(pId);
        int removeIdx = -1;
        vector<pair<int, int>>& pData = p.data;
        for(int i = 0; i < pData.size(); i++) {
            if(pData[i].first == dId) {
                p.leftMem += pData[i].second; // release
                removeIdx = i;
            }
        }
        pData.erase(pData.begin() + removeIdx);
    }

    bool DeleteDevice(int deviceId)
    {
        // cant find
        if(deviceAddr.find(deviceId) == deviceAddr.end()) {
            return false;
        }
        string addr = deviceAddr[deviceId];
        int groupId = decodeDeviceAddr(addr).first;
        int procId = decodeDeviceAddr(addr).second;

        releaseDeviceMem(groupId, procId, deviceId);
        deviceAddr.erase(deviceId);
        return true;
    }

    // 可以使用std::get访问tuple中的成员，比如std::get<0>(obj)可访问obj中第一个成员
    vector<tuple<int, int, int>> QueryDevice(int deviceType)
    {
        // deviceId memSize procId
        vector<tuple<int, int, int>> res;

        // 每个进程
        for(const auto& p: totalData[deviceType].data) {
            int pid = p.procId;
            vector<pair<int, int>> data = p.data;
            // 每个设备
            for(const auto& d: data) {
                res.push_back(make_tuple(d.first, d.second, pid));
            }
        }

        auto cmp = [] (const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
            if(get<1>(t1) == get<1>(t2)) {
                if(get<2>(t1) == get<2>(t2)) {
                    return get<0>(t1) < get<0>(t2);
                }
                return get<2>(t1) < get<2>(t2);
            }
            return get<1>(t1) > get<1>(t2);
        };

        sort(res.begin(), res.end(), cmp);
        return res;
    }
};

// int main() {
//     DeviceMgtSystem sys(2, 200);
//     sys.CreateDevice(8, 1, 50);
//     sys.CreateDevice(12, 1, 30);
//     // sys.CreateDevice(12, 2, 20);
//     //
//     //
//     // sys.QueryDevice(1);
//     // sys.QueryDevice(2);
//     //
//     // sys.CreateDevice(15, 1, 40);
//     // sys.CreateDevice(6, 2, 30);
//     // sys.CreateDevice(19, 2, 60);
//
//     // bool result = sys.DeleteDevice(18);
//
//     cout << endl;
//
// }
