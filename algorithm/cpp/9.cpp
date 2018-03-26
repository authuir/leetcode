#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		char input[11] = {0};
		sprintf(input, "%d", x);
		string s;
		s.append(input);
		for (int len = s.length(), i = 0;i < len / 2;i++)
		{
			if (s[i] != s[len - 1 - i])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	int a = 0 - 2147483648;
	cout << s.isPalindrome(a) << endl;
	cout << s.isPalindrome(12321) << endl;
	cout << s.isPalindrome(2147483648) << endl;
	cout << s.isPalindrome(2147483647) << endl;
	cout << s.isPalindrome(12321) << endl;
	cout << s.isPalindrome(-12321) << endl;
	cout << s.isPalindrome(-12) << endl;
	cout << s.isPalindrome(123) << endl;
	cout << s.isPalindrome(-123) << endl;
}

