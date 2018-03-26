#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() <= 1) return false;
		int san = s.size() / 2;
		for (int i = 0; i<san; i++)
		{
			if (s.size() % (san - i) == 0)
			{
				int flag = 0;
				for (int m = 0; m<(san - i); m++)
				{
					char standard = s[m];
					for (int n = 0; n<(s.size() / (san - i)); n++)
					{
						if (s[n*(san - i) + m] != standard)
						{
							flag = 1;
							break;
						}
							
					}
				}
				if (flag == 0)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution x;
	cout << x.repeatedSubstringPattern("aba") << endl;
	cout << x.repeatedSubstringPattern("abab") << endl;
	cout << x.repeatedSubstringPattern("aaa") << endl;
	cout << x.repeatedSubstringPattern("ababab") << endl;
	cout << x.repeatedSubstringPattern("abcabcabc") << endl;
	return 0;
}