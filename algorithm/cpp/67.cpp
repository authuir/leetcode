#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() == 0) return b;
		if (b.length() == 0) return a;
		string rtn = "";
		int ex;int jw = 0;
		for (int i = a.length()-1,j = b.length() - 1;i>=0||j>=0;)
		{
			if (i >= 0 && j >= 0)
			{
				ex = (a[i] - '0') + (b[j] - '0') + jw;
				if (ex == 0)
				{
					rtn += '0';
					jw = 0;
				}
				else if (ex == 1)
				{
					rtn += '1';
					jw = 0;
				}
				else if (ex == 2)
				{
					rtn += '0';
					jw = 1;
				}
				else if (ex == 3)
				{
					rtn += '1';
					jw = 1;
				}
			}
			else if (i >= 0)
			{
				ex = a[i] + jw - '0';
				if (ex == 0)
				{
					rtn += '0';jw = 0;
				}
				else if (ex == 1)
				{
					rtn += '1';jw = 0;
				}
				else if (ex == 2)
				{
					rtn += '0';jw = 1;
				}
			}
			else if (j >= 0)
			{
				ex = b[j] + jw - '0';
				if (ex == 0)
				{
					rtn += '0';jw = 0;
				}
				else if (ex == 1)
				{
					rtn += '1';jw = 0;
				}
				else if (ex == 2)
				{
					rtn += '0';jw = 1;
				}
			}
			i--;j--;
		}
		if (jw == 1)
			rtn += "1";
		string s(rtn.rbegin(), rtn.rend());
		return s;
	}
};

int main()
{
	Solution s;
	cout << s.addBinary("11","1");
	cout << s.addBinary("1011", "11");
	return 0;
}