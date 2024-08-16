//
// Created by Younghusband on 2024/8/12.
//
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    // abcd efgh ijkl mnop qrst
    unordered_map<char, stack<int>> map;

    void psh(string oper, unordered_map<char, stack<int>>& map) {
        char stackname = oper.substr(0, 1)[0];
        int data = stoi(oper.substr(2));
        if(map[stackname].size() >= 32) {
            return;
        }
        if(data > 1024) {
            data %= 1024;
        }
        map[stackname].push(data);
    }
    void add(string oper, unordered_map<char, stack<int>>& map) {

    }

    void div(string oper, unordered_map<char, stack<int>>& map) {

    }

    void pop(string oper, unordered_map<char, stack<int>>& map) {

    }

    void mul(string oper, unordered_map<char, stack<int>>& map) {

    }

    array<int, 20> StackCalculator(const vector<string>& instructions)
    {
        array<int, 20> res;
        fill(res.begin(), res.end(), -1);
        for(const auto& item: instructions) {
            string operCode = item.substr(0, 3);
            string operObj = item.substr(4);
            if(operCode == "PSH") {
                psh(operObj, map);
            } else if(operCode == "ADD") {
                add(operObj, map);
            } else if(operCode == "DIV") {
                div(operObj, map);
            } else if(operCode == "POP") {
                pop(operObj, map);
            } else {
                // MUL
                mul(operObj, map);
            }

            // print from a to t
            for(char c = 'a'; c <= 't'; c++) {
                res[c - 'a'] = map[c].top();
            }
        }
        return res;
    }

};