#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.size() <= 1) return true;
		int cases = 0;
		if (word[0] >= 'a' && word[0] <= 'z' && word[1] >= 'A' && word[1] <= 'Z')
			return false;
		else if (word[0] >= 'a' && word[0] <= 'z' && word[1] >= 'a' && word[1] <= 'z')
			cases = 0;
		else if (word[0] >= 'A' && word[0] <= 'Z' && word[1] >= 'a' && word[1] <= 'z')
			cases = 1;
		else if (word[0] >= 'A' && word[0] <= 'Z' && word[1] >= 'A' && word[1] <= 'Z')
			cases = 2;

		for (int i = 2; i<word.size(); i++)
		{
			if (cases == 0 || cases == 1)
			{
				if (word[i] >= 'A' && word[i] <= 'Z')
					return false;
			}
			else
			{
				if (word[i] >= 'a' && word[i] <= 'z')
					return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution x;
	cout<<x.detectCapitalUse("mL");
	return 0;
}