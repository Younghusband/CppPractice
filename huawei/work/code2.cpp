#include <vector>

using namespace std;

class Solution {
public:
    int GetMaxReduced(const vector<int>& records)
    {
        int size = records.size();
        int highIndex = 0;
        int maxDeduce = 0;

        for(int i = 0; i < size; i++) {
            if(records[i] >= records[highIndex]) {
                highIndex = i;

            } else {
                // 当前小于最高点
                int curDeduce = records[highIndex] - records[i];
                maxDeduce = max(curDeduce, maxDeduce);
            }
        }
        return maxDeduce;
    }
};