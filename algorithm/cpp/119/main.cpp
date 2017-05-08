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
			if (i - 1<0)
				rtn.push_back(rqs[i]);
			else if (i >= rqs.size())
				rtn.push_back(rqs[i - 1]);
			else
				rtn.push_back(rqs[i - 1] + rqs[i]);
		}
		return rtn;
	}

public:
	vector<int> getRow(int numRows) {
		numRows++;
		vector<vector<int>> rtn;
		vector<int> t;
		if (numRows <= 0) return t;
		t.push_back(1);
		rtn.push_back(t);

		for (int i = 2; i < numRows + 1; i++)
		{
			t = get(i, rtn[i - 2]);
			rtn.insert(rtn.end(), t);
			
		}
		return t;
	}
};

int main()
{
	Solution x;
	vector<int> rtn = x.getRow(0);
	cout << rtn[0];
	return 0;
}