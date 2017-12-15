#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
	vector<int> pool = vector<int>{ 1,2,3,4,5,6,7,8,9 };
	vector<vector<int>> rtn;
	int kk;
	int nn;

	void trave(vector<int> rsd, int ceng)
	{
		if (ceng == 0)
		{
			int sum = 0;
			vector<int> sums;
			for (int i = 0; i < rsd.size(); i++)
			{
				sum += pool[rsd[i]];
				sums.push_back(pool[rsd[i]]);
			}
			if (sum == nn)
			{
				rtn.push_back(sums);
			}
			return;
		}

		int i = 0;
		if (rsd.size() > 0)
			i = rsd.back() + 1;
		for (; i<pool.size(); i++)
		{
			rsd.push_back(i);
			int sum = 0;
			for (int i = 0; i < rsd.size(); i++)
			{
				sum += pool[rsd[i]];
			}
			if (sum > nn)
				return;
			trave(rsd, ceng - 1);
			rsd.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum3(int k, int n) {


		int thex = 0;
		for (int i = 1; i< k; i++)
			thex += i;
		for (auto iter = pool.begin(); iter != pool.end();)
		{
			if (*iter > n - thex)
			{
				iter = pool.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		kk = k;
		nn = n;

		if (pool.size() < k)
			return rtn;

		trave(vector<int>{}, k);

		return rtn;
	}
};

int main()
{
	Solution x;
	x.combinationSum3(3, 7);
	return 0;
}

