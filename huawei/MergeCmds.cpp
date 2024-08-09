//
// Created by Younghusband on 2024/8/9.

// 输入：
// ["port trunk allow-pass vlan 10 20 to 30",
// "port trunk allow-pass vlan 15 to 25 9",
// "undo port trunk allow-pass vlan 10 to 20 23"]
// 输出：
// "port trunk allow-pass vlan 9 21 to 22 24 to 30"
// 解释：
// 第一条命令后，允许通过的vlan-id为：10, [20,30]
// 第二条命令后，允许通过的vlan-id为：[9,10], [15,30]
// 第三条命令后，允许通过的vlan-id为：9, [21,22], [24,30]
//
//
// 输入：
// ["undo port trunk allow-pass vlan 10 to 20",
// "port trunk allow-pass vlan 17 to 20 24 to 4094",
// "port trunk allow-pass vlan 21 to 24",
// "port trunk allow-pass vlan 1 to 15 4095 16"]

// 输出：
// "port trunk allow-pass vlan 1 to 4095"
// 解释：
// vlan-id 从1到4095都允许通过
//

#include <vector>
#include <string>
#include<map>
using namespace std;

class Solution {
public:
    //最后执行一次，将01串转化为所需要的格式
    string Encode(const string &str) {
        string res;
        map<int, bool> nums;
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                int j = 1;
                while (str[i + j] == '1') {
                    j++;
                }
                if (j != 1) {
                    res += " " + to_string(i) + " to " + to_string(i + j - 1);
                    i += j - 1;
                } else {
                    res += " " + to_string(i);
                }
            }
        }
        return res;
    }

    //将str串用split分割为若干小节，将结果存在res数组中
    void Splitby(string str, vector<string> &res, string split) {
        while (true) {
            int i = str.find(split);
            if (i == -1) {
                break;
            }
            res.emplace_back(str.substr(0, i));
            str.erase(str.begin(), str.begin() + i + 1);
        }
        res.emplace_back(str);
    }

    void Decode(string str, string &qujian, char changeto) {
        //以空格分割串
        map<int, bool> nums;
        vector<string> tmp;
        Splitby(str, tmp, " ");
        //记录数字和区间端点信息
        int n = tmp.size();
        for (int i = 0; i < n; i++) {
            if (tmp[i] == "to") {
                nums[stoi(tmp[i - 1])] = true;
                nums[stoi(tmp[i + 1])] = true;
                i++;
                continue;
            }
            nums[stoi(tmp[i])] = false;
        }
        //维护区间内容
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (it->second) {
                int left = it->first;
                it++;
                int right = it->first;
                for (; left <= right; left++) {
                    qujian[left] = changeto;
                }
            } else {
                qujian[it->first] = changeto;
            }
        }
    }

    string MergeCmds(const vector<string> &cmds) {
        string qujian(4096, '0'); //待维护的01串
        int n = cmds.size();
        for (int i = 0; i < n; i++) {
            if (cmds[i][0] == 'p') {
                Decode(cmds[i].substr(27, 999), qujian, '1');
            } else if (cmds[i][0] == 'u') {
                Decode(cmds[i].substr(32, 999), qujian, '0');
            }
        }
        return "port trunk allow-pass vlan" + Encode(qujian);
    }
};
