//
// Created by Younghusband on 2024/9/20.
//


// 一个简易的文本编辑器，初始为空行，光标在行首，默认小写；请实现如下功能：
//
// a-z 按下键盘对应的 26 个字母键，在光标位置输入一个字符。
// @ 表示大小写切换。
// + 在光标位置换行，把光标右边的内容作为新行插入在当前行之后。
// ~ 表示退格键，可删除光标左边字符；当光标在行首时，将当前行拼接到到上一行（如果存在）行尾。
// - 表示删除键，可删除光标右边字符；当光标在行尾时，将下一行（如果存在）拼接到当前行行尾。
// ^*<> 分别表示上下左右方向键：
// 左右移动，光标横向移动一个位置：
// 当光标在行首时，左移到上一行（如果存在）行尾；
// 当光标在行尾时，右移到下一行（如果存在）行首。
// 上下移动，光标纵向移动一行：
// 若在首行上移，或在末行下移，则移动无效；
// 相邻行：如果目标行内容长度小于光标的列位置，则光标移动到目标行行尾。注意：仅根据当前光标的列位置来移动，不记忆之前的位置。



/**
 * 这题当时死磕了很久的原因主要在于对于换行操作的理解。。 要符合题意，不能瞎想，理解题意最大
 **/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    int cursorRow;
    int cursorIndex;
    vector<string> lines;
    bool isDaxie;

    void back() {
        // 位于行首
        if(cursorIndex == 0) {
            if(cursorRow > 0) {
                cursorIndex = lines[cursorRow - 1].size();  // 光标新位置
                lines[cursorRow - 1] += lines[cursorRow];
                lines.erase(lines.begin() + cursorRow);
                cursorRow--;
            }
        } else {
            cursorIndex--;
            lines[cursorRow].erase(cursorIndex, 1);
        }
    }

    void deleteC() {
        int totalRow = lines.size();
        // 在行尾
        if(cursorIndex == lines[cursorRow].size()) {
            if(cursorRow < totalRow - 1) {
                // 拼接下一行
                lines[cursorRow] += lines[cursorRow + 1];
                // 删除下一行
                lines.erase(lines.begin() + cursorRow + 1);
            }
        } else {
            lines[cursorRow].erase(cursorIndex, 1);  // 仅应该删除这个位置的一个值
        }
    }

    void left() {
        // 已在行首
        if(cursorIndex == 0) {
            // 非首行
            if(cursorRow > 0) {
                cursorRow--;
                cursorIndex = lines[cursorRow].size();
            }
        } else {
            cursorIndex--;
        }
    }

    void right() {
        // 已在行尾
        if(cursorIndex == lines[cursorRow].size()) {
            if(cursorRow < lines.size() - 1) {
                cursorRow++;
                cursorIndex = 0;
            }
        } else {
            cursorIndex++;
        }
    }

    void up() {
        if(cursorRow > 0) {
            cursorRow--;
            int upperEndPos = lines[cursorRow].size();
            cursorIndex = min(cursorIndex, upperEndPos);
        }
    }

    void down() {
        if(cursorRow < lines.size() - 1) {
            cursorRow++;
            int downEndPos = lines[cursorRow].size();
            cursorIndex = min(cursorIndex, downEndPos);
        }
    }

    void newLine() {
        string newLine = lines[cursorRow].substr(cursorIndex); // 暂存光标右侧
        lines[cursorRow].erase(cursorIndex); // 删除右侧
        lines.insert(lines.begin() + cursorRow + 1, newLine);
        cursorRow++;
        cursorIndex = 0;
    }

    /**
     * 需要记录光标所在行列
     *
     */

    vector<string> StrEdit(const string& inputStr)
    {
        cursorRow = 0;
        cursorIndex = 0;
        isDaxie = false;
        for(char c : inputStr) {
            if(lines.empty()) {
                lines.push_back("");
            }
            switch(c) {
                case '@': // 切换大小写
                    isDaxie = !isDaxie;
                    break;
                case '+':
                    newLine();
                    break;
                case '~':
                    back();
                    break;
                case '-':
                    deleteC();
                    break;
                case '^':
                    up();
                    break;
                case '*':
                    down();
                    break;
                case '<':
                    left();
                    break;
                case '>':
                    right();
                    break;
                default:
                    if(c >= 'a' && c <= 'z') {
                        string& currentLine = lines[cursorRow];
                        if(isDaxie) {
                            c = toupper(c);
                        }
                        currentLine.insert(cursorIndex, 1, c);
                        cursorIndex++;
                    }
                break;
            }
        }

        return lines;
    }
};

// int main() {
//     // string input("aaaa+bbbb~@cc<<<^--d@d");
//     // string input("^*><+++^^a**b+^");
//     // string input("za+b+cd^*e^^~*~>>~");
//     string input("aaaa+bbbbc");
//     Solution slo;
//     vector<string> res = slo.StrEdit(input);
//
//     for(string item: res) {
//         cout << item << endl;
//     }
//     cout << "end lines...";
// }
