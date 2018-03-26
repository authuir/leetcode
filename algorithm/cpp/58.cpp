#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if ("" == s)
			return 0;
		string word;
		int mod = 0;//new:0;append:1
		for (int i = 0;i < s.length();i++)
		{
			if (mod == 0 && s[i] != ' ')
			{
				word = "";
			}
			if (s[i] != ' ')
			{
				word.append(1, s[i]);
				mod = 1;
			}	
			else
				mod = 0;
		}

		return word.length();
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLastWord("AB");
	cout << s.lengthOfLastWord("AB fd");
	cout << s.lengthOfLastWord("a ");
	cout << s.lengthOfLastWord("b   a    ");

}