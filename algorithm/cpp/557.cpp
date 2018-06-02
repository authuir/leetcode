#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;


class Solution {
public:
	string reverseWords(string s) {
		if (s.size() <= 1)
			return s;
		string tmp;
		string rtn;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] != ' ')
			{
				tmp.push_back(s[i]);
			}
			else
			{
				reverse(tmp.begin(), tmp.end());
				rtn += tmp;
				rtn.push_back(' ');
				tmp = "";
			}
		}
		if (tmp.size() >= 1)
		{
			reverse(tmp.begin(), tmp.end());
			rtn += tmp;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.reverseWords("fdsf");

	return 0;
}