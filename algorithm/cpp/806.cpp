#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int record = 0;
        int rtn = 1;
        for (auto iter : S)
        {
            record = record + widths[iter-'a'];
            if (record > 100)
            {
                record = widths[iter-'a'];
                rtn++;
            }
                
        }
        vector<int> result;
        result.push_back(rtn);
        result.push_back(record);
        return result;
    }
};