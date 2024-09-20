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


#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Content {

    int cursorRow;
    int cursorIndex;
    vector<string> lines;
    bool isDaxie;

};

class Solution {

public:

    void back(vector<string>& line, int& row, int& index) {
        // 位于行首
        if(index == 0) {
            if(row > 0) {
                line[row - 1] += line[row];
                line.erase(line.begin() + row);
                index = line[row - 1].size() - 1;  // 光标新位置
                row = row - 1;
            }
        } else {
            index--;
            line[row].erase(index, 1);
        }
    }

    void deleteC(vector<string>& line, int& row, int& index) {
        int totalRow = line.size();
        // 在行尾
        if(index == line[row].size()) {
            if(row < totalRow - 1) {
                // 拼接下一行
                line[row] += line[row + 1];
                // 删除下一行
                line.erase(line.begin() + row + 1);
            }
        } else {
            line[row].erase(index, 1);  // 仅应该删除这个位置的一个值
        }
    }

    void left(vector<string>& line, int& row, int& index) {
        // 已在行首
        if(index == 0) {
            // 非首行
            if(row > 0) {
                row--;
                index = line[row].size();
            }
        } else {
            index--;
        }

    }


    void right(vector<string>& line, int& row, int& index) {
        // 已在行尾
        if(index == line[row].size()) {
            if(row < line.size() - 1) {
                row++;
                index = 0;
            }
        } else {
            index++;
        }
    }

    void up(vector<string>& line, int& row, int& index) {
        if(row > 0) {
            row--;
            int upperEndPos = line[row].size();
            index = (index > upperEndPos) ? upperEndPos : index;
        }
    }

    void down(vector<string>& line, int& row, int& index) {
        if(row < line.size() - 1) {
            row++;
            int downEndPos = line[row].size();
            index = (index > downEndPos) ? downEndPos : index;
        }
    }

    /**
     * 需要记录光标所在行列
     *
     */

    vector<string> StrEdit(const string& inputStr)
    {
        Content content;
        content.cursorRow = 0;
        content.cursorIndex = 0;
        content.isDaxie = false;
        for(char c : inputStr) {
            if(content.lines.empty()) {
                content.lines.push_back("");
            }
            switch(c) {
                case '@': // 切换大小写
                    content.isDaxie = !content.isDaxie;
                    break;
                case '+':
                    // 加一行空白行
                    content.lines.push_back("");
                    content.cursorIndex = 0;
                    content.cursorRow++;
                    break;
                case '~':
                    back(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                case '-':
                    deleteC(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                case '^':
                    up(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                case '*':
                    down(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                case '<':
                    left(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                case '>':
                    right(content.lines, content.cursorRow, content.cursorIndex);
                    break;
                default:
                    string& currentLine = content.lines[content.cursorRow];
                    if(content.isDaxie) {
                        c = toupper(c);
                    }
                    currentLine.insert(content.cursorIndex, 1, c);
                    content.cursorIndex++;
                break;
            }
        }

        return content.lines;
    }

};

// int main() {
//     // string input("aaaa+bbbb~@cc<<<^--d@d");
//     // string input("^*><+++^^a**b+^");
//     string input("za+b+cd^*e^^~*~>>~");
//     Solution slo;
//     vector<string> res = slo.StrEdit(input);
//
//     for(string item: res) {
//         cout << item << endl;
//     }
// }
