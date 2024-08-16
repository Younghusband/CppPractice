//
// Created by Younghusband on 2024/8/12.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int StrBackspace(const string& inputStr)
    {
        stack<char> stack;
        for(char c: inputStr) {
            if(c != '$') {
                stack.push(c);
            } else {
                if(!stack.empty()) {
                    stack.pop();
                }
            }
        }
        return stack.size();
    }
};

// int main() {
//     Solution slo;
//     cout << slo.StrBackspace("$c$df");
// }