#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n <= 1) return 0;
        if (dp.count(n)) return dp[n];
        int rtn = n;
        for (int i=n-1; i>=2; i--)
        {
            if (n%i == 0)
            {
                int x = n/i +minSteps(i);
                if (x < rtn) rtn = x;
            }
        }
        dp.insert({n,rtn});
        return rtn;
    }
private:
    unordered_map<int, int> dp;
};

int main()
{
	Solution x;

	cout << x.minSteps(16) << endl;
	return 0;
}
