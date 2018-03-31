#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
private:
    int** dp = NULL;
    int** sum = NULL;
    int getDp(int i, int j, vector<int>& nums)
    {
        if (i > j || i<0 || j<0)
            return 0;
        else if (i == j)
            return nums[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = getSum(i, j, nums) - min( getDp(i, j-1, nums), getDp(i+1, j, nums) );
        return dp[i][j];
    }
    int getSum(int i, int j, vector<int>& nums)
    {
        if (i > j || i<0 || j<0)
            return 0;
        else if (i == j)
            return nums[i];
        if (sum[i][j] != -1)
            return sum[i][j];
        sum[i][j] = nums[i] + getSum(i+1, j, nums);
        return sum[i][j];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        dp = new int*[nums.size()]; 
        sum = new int*[nums.size()];
        for (int i=0;i<nums.size();i++)
        {
            dp[i] = new int[nums.size()];
            sum[i] = new int[nums.size()];
            for (int j=0;j<nums.size();j++)
            {
                dp[i][j] = -1;
                sum[i][j] = -1;
            }
        }
        cout << "getSum " << getSum(0, nums.size()-1, nums) << endl;
        cout << "getDp  " << getDp(0, nums.size()-1, nums) << endl;
        
        return getDp(0, nums.size()-1, nums) >= (getSum(0, nums.size()-1, nums) - getDp(0, nums.size()-1, nums));
    }
    ~Solution()
    {
        delete[] dp;
        delete[] sum;
    }
};

int main()
{
    Solution x;
    vector<int> a{2,4,55,6,8};
    cout << x.PredictTheWinner(a);
    return 0;
}
