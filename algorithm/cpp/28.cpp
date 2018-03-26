#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() <= 0)
			return 0;
		int stat = 0;
		for (int i = 0;i < haystack.length();i++)
		{
			if (haystack.length() - i < needle.length())
				break;
			for (int j = 0;j < needle.length();j++)
			{
				if (needle[j] == haystack[i + j])
				{
					if (j == needle.length() - 1)
						return i;
				}
				else
					break;
			}
		}
		return -1;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	
	cout << x.strStr("", "") << endl;
	return 0;
}
