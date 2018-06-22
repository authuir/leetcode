#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            if (tmp[nums[i] - 1] == 0)
                tmp[nums[i] - 1] = 1;
            else if (tmp[nums[i] - 1] == 1)
                tmp[nums[i] - 1] = 2;
        }
        vector<int> rtn(2);
        for (int i=0; i<nums.size(); i++) {
            if (tmp[i] == 0)
                rtn[1] = i+1;
            else if (tmp[i] == 2)
                rtn[0] = i+1;
        }
        return rtn;
    }
};


int main(int argc, char const *argv[])
{
    Solution x;
    vector<int> input = {1,2,2,4};
    x.findErrorNums(input);
    return 0;
}
