#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int calc(int num)
	{
		num = num - 2;
		return num*(num + 1) / 2;
	}

public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
			return 0;
		int rtn = 0;
		vector<int> diff;
		int tmp = A[0];
		for (int i = 1; i < A.size(); i++)
		{
			diff.push_back(A[i] - tmp);
			tmp = A[i];
		}

		int cnt = 2;
		tmp = diff[0];
		for (int i = 1; i < diff.size(); i++)
		{
			if (tmp != diff[i])
			{
				if (cnt >= 3)
					rtn += calc(cnt);
				cnt = 2;
				tmp = diff[i];
			}
			else
			{
				cnt++;
			}
		}
		if (cnt >= 3)
			rtn += calc(cnt);
		return rtn;
	}
};

int main()
{
	Solution x;
	cout<<x.numberOfArithmeticSlices(vector<int>{1,2,3});
	return 0;
}