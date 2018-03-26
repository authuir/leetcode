#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        dp = new vector<int>(prices.size(), -1);
        dp_sell = new vector<int>(prices.size(), -1);
        int rtn = 0;
        int tmp = 0;
        for (int i=0;i<prices.size();i++)
        {
            int tmp = dpval(i, prices, fee);
            if (rtn < tmp)
                rtn = tmp;
        }
        // for (int i=0;i<prices.size();i++)
        //     cout << "dp[" << i << "]=" << (*dp)[i] << endl;
        // for (int i=0;i<prices.size();i++)
        //     cout << "dpsell[" << i << "]=" << (*dp_sell)[i] << endl;
        return rtn;
    }
    inline int dpval(int i, vector<int>& prices, int& fee)
    {
        if (i <= 0)
        {
            (*dp)[i] = 0;
            return 0;
        }
        if ((*dp)[i] != -1)
            return (*dp)[i];
        int j = i;
        int here = prices[i];
        
        if ((*dp_sell)[i-1] >= 0 && prices[i] > prices[(*dp_sell)[i-1]])
        {
            (*dp)[j] = (*dp)[i-1] + prices[i] - prices[(*dp_sell)[i-1]];
            (*dp_sell)[i] = i;
        }
        else
        {
            (*dp)[j] = (*dp)[i-1];
            (*dp_sell)[i] = (*dp_sell)[i-1];
        }
        
        i--;
        int limit = 0;
        if (i >= 0)
            limit = (*dp_sell)[i];
        while (i>limit)
        {
            int profit = 0;
            if (prices[i] < here - fee)
            {
                profit = dpval(i-1, prices, fee) + here - prices[i] - fee;
                if (profit > (*dp)[j])
                {
                    (*dp)[j] = profit;
                    (*dp_sell)[j] = j;
                }
            }
            i--;
        }
        return (*dp)[j];
    }
    vector<int> * dp;
    vector<int> * dp_sell;
};

int main()
{
	Solution x;
    vector<int> a{1,3,7,5,10,3};
    cout << x.maxProfit(a, 3);
	return 0;
}
