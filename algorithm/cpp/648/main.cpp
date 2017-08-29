#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	// return 0: equal, 1: s1 is root of s2, 2: s2 is root of s1, -1: none
	int isRoot(string s1, string s2)
	{
		if (s1.length() == s2.length())
		{
			if (s1 == s2)
			{
				return 0;
			}
		}
		else
		{
			int rtn = 1;
			string a, b;
			a = s1;
			b = s2;
			if (s1.length() > s2.length())
			{
				rtn = 2;
				a = s2;
				b = s1;
			}

			if (b.substr(0, a.length()) == a)
			{
				return rtn;
			}
			else
				return -1;
		}
		return -1;
	}

	void clearRoot(vector<string>& dict)
	{
		for (auto iter = dict.begin(); iter != dict.end()-1 && iter != dict.end(); )
		{
			for (auto xter = iter+1; xter != dict.end(); )
			{
				int rx = isRoot(*iter, *xter);
				if (rx == 0 || rx == 1)
				{
					xter = dict.erase(xter);
				}
				else if (rx == 2)
				{
					iter = dict.erase(iter);
					break;
				}
				else
				{
					xter++;
				}
			}
			iter++;
		}
	}

	string replace(vector<string>& dict, string sentence)
	{
		string rtn;
		string tmp = "";
		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ')
				tmp.push_back(sentence[i]);
			else
			{
				string tx = tmp;
				tmp = "";
				int flag = 1;
				for (auto iter = dict.begin(); iter != dict.end(); iter++)
				{
					int rx = isRoot(*iter, tx);
					if (rx == 1)
					{
						rtn = rtn + *iter + " ";
						flag = 0;
						break;
					}
				}
				if (flag)
					rtn = rtn + tx + " ";
			}
		}
		int flag = 1;
		for (auto iter = dict.begin(); iter != dict.end(); iter++)
		{
			int rx = isRoot(*iter, tmp);
			if (rx == 1)
			{
				rtn = rtn + *iter;
				flag = 0;
				break;
			}
		}
		if (flag)
			rtn = rtn + tmp;
		return rtn;
	}

public:
	string replaceWords(vector<string>& dict, string sentence) {
		if (dict.size() <= 0)
			return sentence;
		clearRoot(dict);
		return replace(dict, sentence);
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	x.replaceWords(vector<string>{"a", "abc", "ab"}, "adsf sdfsdf");
	return 0;
}
