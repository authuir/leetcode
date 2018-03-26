#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long int x = 0;
		char isnag = '+';
		if (str.length() < 1)
			return 0;
		int cnt = str.length();
		while ( (str[0] > '9' || str[0] < '0') && cnt >0)
		{
			if (str[0] == '-')
			{
				isnag = '-';
				str.erase(0, 1);
				break;
			}
			else if (str[0] == '+')
			{
				isnag = '+';
				str.erase(0, 1);
				break;
			}
			else if (str[0] == ' ')
			{
				str.erase(0, 1);
			}
			cnt--;
		}
		for (int i = 0;i < str.length(); i++)
		{
			if (str[i] > '9' || str[i] < '0')
			{
				str.erase(i, str.length() - i);
			}
		}
		if (str.length() < 1)
			return 0;
		if (str.length() > 10)
			return isnag=='-'? 0-(long long)2147483648: 2147483647;
		for (int i = 0;i < str.length(); i++)
		{
			if (str[i]<'0' || str[i]>'9')
				break;
			long long tmp = (str[i] - '0')*pow(10, str.length() - i - 1);
			x += tmp;
		}
		int rtn = 0;
		if (x >= 2147483648 && isnag == '+')
			rtn = 2147483647;
		else if (x > 2147483648 && isnag == '-')
			rtn = 2147483648;
		else if (x < 0 - (long long int)2147483648)
			rtn = 0 - (int)2147483648;
		else
			rtn = x;

		if (isnag == '-')
			rtn = 0 - rtn;
		return rtn;
	}
};

int main()
{
	Solution s;
	
	cout << s.myAtoi("      -11919730356x") << endl;
	cout << s.myAtoi("9223372036854775809") << endl;
	cout << s.myAtoi(" b11228552307") << endl;
	cout << s.myAtoi("abc") << endl;
	cout << s.myAtoi("2147483648") << endl;
	cout << s.myAtoi("2147483647") << endl;
	cout << s.myAtoi("-2147483648") << endl;
}