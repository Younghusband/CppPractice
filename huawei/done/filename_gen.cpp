//
// Created by Younghusband on 2024/8/13.
//
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: 上机编程认证
 * Caution：本地调试时，只编译运行main.cpp文件，不要链接这个文件！因为本文件已经被main.cpp文件include了
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    string generator(string src, int cnt) {
        return src + "(" + to_string(cnt) + ")";
    }

    vector<string> GenerateFileName(const vector<string>& fileNames)
    {
        if(fileNames.size() == 1) {
            return fileNames;
        }
        vector<string> res;
        unordered_map<string, int> map;
        for(int i = 0; i < fileNames.size(); i++) {
            string cur = fileNames[i];
            auto it = map.find(cur);
            if(it == map.end()) {
                map[cur] = 1;
            } else {
                map[cur] = map[cur] + 1;
            }
            int curCnt = map[cur];
            if(curCnt > 1) {
                res.push_back(generator(fileNames[i], curCnt));
            } else {
                res.push_back(fileNames[i]);
            }
        }
        return res;
    }
};

// int main() {
//     Solution slo;
//     vector<string> vec = {"myfile", "yourfile", "myfile", "myfile"};
//     vector<string> res = slo.GenerateFileName(vec);
//     for(const auto& item: res) {
//         cout << item << " ";
//     }
// }