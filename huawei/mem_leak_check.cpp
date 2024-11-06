//
// Created by Younghusband on 2024/11/5.
//

#include <string>
#include <vector>
#include <tuple>

using namespace std;

class MemLeakDetectSystem {
public:
    MemLeakDetectSystem()
    {

    }

    void OnMemoryAlloced(int memAddr, int size, const string& filename, int line)
    {

    }

    int OnMemoryFreed(int memAddr)
    {
        return 0;
    }

    // 可以使用std::get访问tuple中的成员，比如std::get<0>(obj)可访问obj中第一个成员
    vector<tuple<string, int, int>> StatLeakInfo(int topNum)
    {
        return {};
    }
};
