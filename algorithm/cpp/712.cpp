#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        dp = new int[s1.size() * s2.size()];
        x = s1.size();
        memset((void *)dp, -1, sizeof(int[s1.size() * s2.size()]));
        return search(s1.size()-1, s2.size()-1, s1, s2);
    }
private:
    int * dp;
    int x;
    inline int search(int i, int j, const string & s1, const string & s2)
    {
        if (i<0&&j<0)
            return 0;
        else if (i>=0&&j<0)
            return search(i-1, j, s1, s2) + s1[i];
        else if (i<0&&j>=0)
            return search(i, j-1, s1, s2) + s2[j];
        if (dp[i+j*x] != -1)
            return dp[i+j*x];
        if (s1[i] == s2[j])
        {
            dp[i+j*x] = search(i-1, j-1, s1, s2);
            return dp[i+j*x];
        }
        else
        {
            dp[i+j*x] = min( search(i-1, j, s1, s2) + s1[i] ,  search(i, j-1, s1, s2) + s2[j] );
            return dp[i+j*x];
        }
    }
};

int main()
{
    Solution x;
    cout << x.minimumDeleteSum("delete", "leet");
    return 0;
}
