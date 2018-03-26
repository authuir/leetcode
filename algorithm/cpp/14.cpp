#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int  minlen = 9999;
		string rtn = "";
		for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
		{
			minlen = (*it).length() < minlen ? (*it).length() : minlen;
		}
		if (minlen == 9999) return "";
		for (int i = 0;i < minlen;i++)
		{
			char thi = (*strs.begin())[i];
			bool allsame = true;
			for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
			{
				if ((*it)[i] != thi)
				{
					return rtn;
				}
			}
			rtn.push_back(thi);
		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	vector<string> arr;
	/*arr.push_back("testddf");
	arr.push_back("testsdf");
	arr.push_back("testasd");
	arr.push_back("testdf");*/
	x.longestCommonPrefix(arr);
}
