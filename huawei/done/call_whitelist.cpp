//
// Created by Younghusband on 2024/9/13.
//
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

class Solution {

    unordered_map<string, tuple<string, int, int>> resMap;
    vector<string> orderedPhone;
    set<string> whiteList;
    set<string> patternList;

public:

    bool inWhite(string phone) {
        if(whiteList.find(phone) != whiteList.end()) {   // 20之后才支持contains
            return true;
        }
        // 检查带通配符的白名单
        for(string p: patternList) {
            size_t pos = p.find_first_of("*");
            if(phone.substr(0, pos) == p.substr(0, pos)) {
                return true;
            }
        }
        return false;
    }

    // 可以使用std::get访问tuple中的成员，比如std::get<0>(obj)可访问obj中第一个成员
    vector<tuple<string, int, int>> GetPhoneRecords(const vector<pair<char, string>>& operations)
    {
        for(const auto& cmd: operations) {
            char c = cmd.first;
            string phone = cmd.second;
            // 打进来
            if(c == 'C') {
                auto it = find(orderedPhone.begin(), orderedPhone.end(), phone);
                if(it == orderedPhone.end()) {
                    orderedPhone.push_back(phone);
                }
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
        vector<tuple<string, int, int>> res = {};
        for(string phone: orderedPhone) {
            tuple<string, int, int> t = resMap[phone];
            res.push_back(t);
        }
        return res;
    }
};
