#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		if (s.size() == 0) return "";
		string rtn;
		int k_cnt = ceil(float(s.size()) / float(k));
		for (int i = 0; i<k_cnt; i++)
		{
			string tmp;
			if (i % 2 == 0)
			{
				if (i == k_cnt - 1)
				{
					tmp.assign(s.begin() + k*i, s.end());
					reverse(tmp.begin(), tmp.end());
					rtn += tmp;
				}
				else
				{
					tmp.assign(s.begin() + k*i, s.begin() + k*(i + 1));
					reverse(tmp.begin(), tmp.end());
					rtn += tmp;
				}
			}
			else
			{
				if (i == k_cnt - 1)
				{
					tmp.assign(s.begin() + k*i, s.end());
					rtn += tmp;
				}
				else
				{
					tmp.assign(s.begin() + k*i, s.begin() + k*(i + 1));
					rtn += tmp;
				}

			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.reverseStr("abcdefg",
		2) << endl;

	return 0;
}