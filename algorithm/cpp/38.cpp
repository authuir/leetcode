#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	string rtnss(string dp)
	{
		string rtn;
		for (int i = 0; i < dp.length();i++)
		{
			int df = 0;

			char x = dp[i];
			df = 1;
			while ((i + 1) != dp.length())
			{
				if (dp[i + 1] != x)
					break;
				else
				{
					df++;
					i++;
				}
			}
			if (df <= 1)
			{
				rtn.push_back('1');
				rtn.push_back(x);
			}
			else
			{
				rtn.push_back('0' + df);
				rtn.push_back(x);
			}			
		}
		return rtn;
	}

public:
	string countAndSay(int n) {

		string rtn = "1";
		while (n > 1)
		{
			rtn = rtnss(rtn);
 			n--;
		}
		return rtn;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.countAndSay(6);
	return 0;
}