/*
*
* tips:
*  需要验证struct 引入 编译为什么出错
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

// struct Proc {
//     int procId;
//     int leftMem;
//     vector<pair<int, int>> data; // device -> mem
// };
//
// struct Group {
//     vector<Proc> data;
// };

class DeviceMgtSystem {

public:
    const int TYPE_NUM = 3;
    // pid, leftmem, data: device /mem
    using Proc = tuple<int, int, vector<pair<int, int>>>;
    unordered_map<int, Proc> totalData;

    unordered_map<int, vector< tuple<int, int, vector<pair<int, int>>> > > totalData;
    int maxmem;

    unordered_map<int, string> deviceAddr;

    vector<tuple<int, int, vector<pair<int, int>>>> createProcs(int procNum, int maxMem) {
        vector<tuple<int, int, vector<pair<int, int>>>> res;
        vector<pair<int, int>> v;
        for(int i = 0; i < procNum; i++) {
            res.push_back(make_tuple(i, maxMem, v));
        }
        return res;
    }

    int loadBalance(vector<tuple<int, int, vector<pair<int, int>>>> data) {
        auto cmp = [](const tuple<int, int, vector<pair<int, int>>>& p1, const tuple<int, int, vector<pair<int, int>>>& p2) {
            int p1m = get<1>(p1);
            int p2m = get<1>(p2);
            int p1d = get<0>(p1);
            int p2d = get<0>(p2);
            if(p1m == p2m) {
                return p1d < p2d;
            }
            return p1m > p2m;
        };

        sort(data.begin(), data.end(), cmp);
        return get<0>(data[0]);
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
            totalData[i] = createProcs(procNum, maxMemSize);
        }
    }

    int CreateDevice(int deviceId, int deviceType, int memSize)
    {
        // by type find group
        // get procId
        int pId = loadBalance(totalData[deviceType]);
        tuple<int, int, vector<pair<int, int>>>& p = totalData[deviceType].at(pId);
        int & mem = get<1>(p);
        if(mem < memSize) {
            return -1;
        }
        mem -= memSize;

        tuple<int, int, vector<pair<int, int>>>& proc = totalData[deviceType][pId];
        get<2>(proc).push_back(make_pair(deviceId, memSize));

        string addr = "";
        addr += to_string(deviceType);
        addr += " ";
        addr += to_string(pId);
        deviceAddr[deviceId] = addr;
        return pId;
    }

    void releaseDeviceMem(int gId, int pId, int dId) {
        tuple<int, int, vector<pair<int, int>>>& p = totalData[gId][pId];
        int removeIdx = -1;
        vector<pair<int, int>>& pData = get<2>(p);
        for(int i = 0; i < pData.size(); i++) {
            if(pData[i].first == dId) {
                get<1>(p) += pData[i].second; // release
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
        for(const auto& p: totalData[deviceType]) {
            int pid = get<0>(p);
            vector<pair<int, int>> data = get<2>(p);
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
//     sys.CreateDevice(18, 2, 50);
//     sys.CreateDevice(3, 2, 30);
//     sys.CreateDevice(12, 2, 20);
//
//
//     sys.QueryDevice(1);
//     sys.QueryDevice(2);
//
//     sys.CreateDevice(15, 1, 40);
//     sys.CreateDevice(6, 2, 30);
//     sys.CreateDevice(19, 2, 60);
//
//     bool result = sys.DeleteDevice(18);
//
//     cout << endl;
//
//
//
//     // deleteDevice(18)
//     // createDevice(26, 2, 70)
//     // queryDevice(1)
//     // queryDevice(2)
//
//
//
// }

// bool compareProc(const Proc p1, const Proc p2) {
//     if(p1.leftMem == p2.leftMem) {
//         return p1.procId < p2.procId;
//     }
//     return p1.leftMem > p2.leftMem;
// }

// bool deviceCmp(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
//     if(get<1>(t1) == get<1>(t2)) {
//         if(get<2>(t1) == get<2>(t2)) {
//             return get<0>(t1) < get<0>(t2);
//         }
//         return get<2>(t1) < get<2>(t2);
//     }
//     return get<1>(t1) > get<1>(t2);
// }