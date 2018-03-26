#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> get(int length, vector<int> rqs)
	{
		vector<int> rtn;
		if (length == 1) return (vector<int>(1));
		for (int i = 0; i < length; i++)
		{
			if (i-1<0)
				rtn.push_back(rqs[i]);
			else if (i>=rqs.size())
				rtn.push_back(rqs[i-1]);
			else
				rtn.push_back(rqs[i - 1]+rqs[i]);
		}
		return rtn;
	}

public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> rtn;
		if (numRows <= 0) return rtn;
		vector<int> x;
		x.push_back(1);
		rtn.push_back(x);
		
		for (int i = 2; i < numRows+1; i++)
		{
			rtn.insert(rtn.end(), get(i, rtn[i-2]));
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	vector<vector<int>> rtn = x.generate(3);
	cout << rtn[0][0];
	return 0;
}