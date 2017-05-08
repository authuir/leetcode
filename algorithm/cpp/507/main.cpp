#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
private:
	vector <int> sto;
	int C(int m, vector<int> input, int lx)
	{
		int rtn = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (m > 1)
			{
				if (i < input.size() - 1)
				{
					vector<int>tmp;
					tmp.assign(input.begin() + 1 + i, input.end());
					C(m - 1, tmp, input[i] * lx);
				}
			}
			else
			{
				if (find(sto.begin(), sto.end(), input[i] * lx) == sto.end())
					sto.push_back(input[i] * lx);
			}
		}
		return rtn;
	}


public:
	bool checkPerfectNumber(int num) {
		if (num <= 3) return false;
		vector<int> divisors{};
		int tmp = num;
		while (true)
		{
			bool flag = false;
			for (int i = 2; i <= tmp; i++)
			{
				if (i<num)
				{
					if (tmp%i == 0)
					{
						divisors.push_back(i);
						tmp = tmp / i;
						if (tmp == 1)
							break;
						break;
					}
				}
				else
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			if (tmp == 1)
				break;
		}
		int rtn = 1;
		for (int iter = 1; iter < divisors.size(); iter++)
		{
			C(iter, divisors, 1);
		}

		for (int iter = 0; iter < sto.size(); iter++)
		{
			rtn += sto[iter];
		}
		if (rtn == num)
			return true;
		else
			return false;
	}
};


int main()
{
	Solution x;
	cout << x.checkPerfectNumber(5) << endl;
	cout << x.checkPerfectNumber(28) << endl;
	cout << x.checkPerfectNumber(99999993) << endl;
	return 0;
}