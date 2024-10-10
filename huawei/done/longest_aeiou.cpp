//
// Created by Younghusband on 2024/10/9.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> pool = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool judge(const char& c) {
    return pool.count(c) > 0;
}

// asdbuiodevauufgh
int GetLongestVowelStringLength(const string& input)
{
    int maxLen = 0;
    int left, right = 0;
    while(right < input.size()) {
        char c = input[right];
        if(!judge(c)) {
            left = right + 1; // 核心
        } else {
            int curLen = right - left + 1;
            maxLen = max(maxLen, curLen);
        }
        right++;
    }
    return maxLen;
}

// int main()
// {
//     string input;
//     cin >> input;
//     cout << GetLongestVowelStringLength(input) << endl;
//     return 0;
// }
