#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> search_needs(vector<int>& needs, vector<int>& special_iter)
	{
		vector<int> rtn;
		for (int i = 0; i<needs.size(); i++)
			if (needs[i] < special_iter[i])
			{
				rtn.push_back(-1);
				rtn[0] = -1;
				return rtn;
			}
			else
			{
				rtn.push_back(needs[i] - special_iter[i]);
			}
		return rtn;
	}
    int getInput(vector<int>& input)
    {
        int rtn = 0;
        for (int i = 0;i<input.size(); i++)
        {
            rtn += input[i]*pow(10,i);
        }
        return rtn;
    }
	int getDp(vector<int>& price, vector<vector<int>>& special, vector<int>& input) {
        int xx = getInput(input);
		auto rst = dp.find(xx);
		if (rst != dp.end())
			return rst->second;
		int rtn = 100000000;
		int flag = 1;
		for (auto iter : input)
		{
			if (iter > 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) return 0;
		for (auto iter : special)
		{
			vector<int> tmp = search_needs(input, iter);
			if (tmp[0] != -1)
			{
				int price_here = iter.back() + getDp(price, special, tmp);
				if (price_here < rtn)
					rtn = price_here;
			}
		}
		for (int i = 0; i<price.size(); i++)
		{
			if (input[i] > 0)
			{
				input[i] = input[i] - 1;
				int price_here = price[i] + getDp(price, special, input);
				if (price_here < rtn)
					rtn = price_here;
				input[i] = input[i] + 1;
			}
		}

		dp.insert({ xx, rtn });
		return rtn;
	}
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		return getDp(price, special, needs);
	}
private:
    unordered_map<int, int> dp;
};

int main()
{
	Solution x;
	vector<int> s1{9,9,7,2,1,3};
	vector<vector<int>> s2;
	s2.push_back(vector<int>{5,2,6,0,0,2,26});
	s2.push_back(vector<int>{1,3,2,0,0,6,17});
	s2.push_back(vector<int>{5,2,2,2,0,5,15});
	s2.push_back(vector<int>{4,0,0,4,3,4,30});

	vector<int> s3{6,3,1,4,5,1};
	cout << x.shoppingOffers(s1, s2, s3) << endl;
	return 0;
}
