//
// Created by Younghusband on 2024/9/13.
//
#include <set>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

class Solution {

    unordered_map<string, tuple<string, int, int>> resMap;
    set<string> whiteList;
    set<string> patternList;

public:

    bool inWhite(string phone) {

        if(whiteList.contains(phone)) {
            return true;
        }
        // 检查带通配符的白名单


        return true;
    }


    // 可以使用std::get访问tuple中的成员，比如std::get<0>(obj)可访问obj中第一个成员
    vector<tuple<string, int, int>> GetPhoneRecords(const vector<pair<char, string>>& operations)
    {


        for(const auto& cmd: operations) {
            char c = cmd.first;
            string phone = cmd.second;
            // 打进来
            if(c == 'C') {
                if(resMap.find(phone) == resMap.end()) {
                    tuple<string, int, int> t = make_tuple(phone, 0, 0);
                    resMap[phone] = t;
                }
                tuple<string, int, int>& cnt = resMap[phone];
                // 接通 + 1
                if(inWhite(phone)) {
                    get<1>(cnt)++;
                }
                // 拒接 + 1
                else {
                    get<2>(cnt)++;
                }
            }
            // 添加白名单
            else {
                // 找到 * 号
                if(phone.find("*") != string::npos) {
                    patternList.insert(phone);
                } else {
                    whiteList.insert(phone);
                }
            }

        }






        return {};
    }
};
