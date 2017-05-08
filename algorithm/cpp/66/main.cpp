#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> rtn;
		int jw =1, bw;
		for (int i = digits.size() - 1;i>=0;i--)
		{
			bw = (digits[i] + jw) % 10;
			jw = (digits[i] + jw) / 10;
			rtn.insert(rtn.begin(),bw);
			if (i==0 && jw!=0)
				rtn.insert(rtn.begin(), jw);
		}
		return rtn;
	}
};


int main()
{
	Solution s;
	vector<int> input = { 0 };
	cout << s.plusOne(input).size();
	input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << s.plusOne(input).size();
	return 0;
}