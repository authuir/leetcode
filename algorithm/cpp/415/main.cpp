#include <algorithm>

class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1 == "") return num2;
		if (num2 == "") return num1;
		string rtn;
		int bw = 0;
		int jw = 0;
		while (num1.size() != 0 && num2.size() != 0)
		{
			bw = int(num1.back() - '0') + int(num2.back() - '0') + jw;
			jw = bw / 10;
			bw = bw % 10;
			rtn.push_back(char(bw + '0'));
			num1.pop_back();
			num2.pop_back();
		}

		if (num1.size() == 0)
		{
			while (num2.size() >0)
			{
				bw = int(num2.back() - '0') + jw;
				jw = bw / 10;
				bw = bw % 10;
				rtn.push_back(char(bw + '0'));
				num2.pop_back();
			}
		}
		else if (num2.size() == 0)
		{
			while (num1.size() >0)
			{
				bw = int(num1.back() - '0') + jw;
				jw = bw / 10;
				bw = bw % 10;
				rtn.push_back(char(bw + '0'));
				num1.pop_back();
			}
		}
		if (jw != 0)
			rtn.push_back(char(jw + '0'));
		reverse(rtn.begin(), rtn.end());
		return rtn;
	}
};