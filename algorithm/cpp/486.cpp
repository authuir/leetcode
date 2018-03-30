#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        bool rtn = false;
        int p1=0, p2=0;
        while (nums.size()>0)
        {
            if (nums.size() == 1)
            {
                p1+=nums[0];
                nums.erase(nums.begin());
            }
            else if (nums.size() == 2)
            {
                p1+=max(nums[0],nums[1]);
                p2+=min(nums[0],nums[1]);
                nums.erase(nums.begin());
                nums.erase(nums.begin());
            }
            else
            {
                if (nums[0]-max(nums[1],nums.back()) > nums.back()-max(nums[0],nums.at(nums.size()-2)))
                {
                    p1+=nums[0];
                    if (nums[1]>nums.back())
                    {
                        p2+=nums[1];
                        nums.erase(nums.begin()+1);
                        nums.erase(nums.begin());
                    }
                    else
                    {
                        p2+=nums.back();
                        nums.erase(nums.begin()+1);
                        nums.erase(nums.begin());
                    }
                }
            }
            
        }

        return p1>p2;
    }
};

int main()
{
    Solution x;
    vector<int> a{1,2,4,8,16,32,15,7,3};
    x.PredictTheWinner(a);
    return 0;
}
