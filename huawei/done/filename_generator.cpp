//
// Created by Younghusband on 2024/10/29.
//

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    unordered_map<string, int> fileCnt;
    vector<string> GenerateFileName(const vector<string>& fileNames)
    {
        vector<string> res;
        for(const auto& file: fileNames) {
            if(fileCnt.find(file) != fileCnt.end()) {
                int cnt = fileCnt[file];
                cnt++;
                fileCnt[file] = cnt;
                string fileName = file;
                fileName += "(";
                fileName += to_string(cnt);
                fileName += ")";
                res.push_back(fileName);
            } else {
                fileCnt[file] = 1;
                res.push_back(file);
            }
        }
        return res;
    }
};
