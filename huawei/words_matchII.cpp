//
// Created by Younghusband on 2024/10/22.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool dfs(const vector<vector<char>>& charMatrix, const string& s, vector<vector<bool>>& visited, int i, int j, int index) {
        if(i < 0 || i >= charMatrix.size() || j < 0 || j >= charMatrix[0].size()) {
            return false;
        }
        if(visited[i][j] || (charMatrix[i][j] != s[index] && charMatrix[i][j] != '?')) {
            return false;
        }
        if(index == s.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        if(dfs(charMatrix, s, visited, i - 1, j, index + 1) || dfs(charMatrix, s, visited, i + 1, j, index + 1)
            || dfs(charMatrix, s, visited, i, j - 1, index + 1) || dfs(charMatrix, s, visited, i, j + 1, index + 1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool canMatch(const vector<vector<char>>& charMatrix, const string& s) {
        int row = charMatrix.size();
        int col = charMatrix[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(charMatrix[i][j] == s[0] || charMatrix[i][j] == '?') {
                    if (dfs(charMatrix, s, visited, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    // 待实现函数，在此函数中填入答题代码;
    int GetMatchedWordCount(const vector<vector<char>>& charMatrix, const vector<string>& words)
    {
        int matchCnt = 0;
        for(const string& word: words) {
            // matchCnt += canMatch(charMatrix, word);
            if(canMatch(charMatrix, word)) {
                matchCnt++;
            }
        }
        return matchCnt;
    }
};


