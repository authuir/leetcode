#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	bool isPalindrome(string s) {
		string rtn;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				rtn.push_back((char)(s[i] + 32));
			else if (s[i] >= 'a' && s[i] <= 'z')
				rtn.push_back((char)(s[i]));
			else if (s[i] >= '0' && s[i] <= '9')
				rtn.push_back((char)(s[i]));
		}
		for (int i = 0,a = rtn.size()-1; i < rtn.length() / 2; i++)
		{
			if (rtn[i] != rtn[a - i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution x;
	cout << x.isPalindrome("aba");
	return 0;
}