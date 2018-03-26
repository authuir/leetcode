#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> alpha;
		alpha.push_back("qwertyuiopQWERTYUIOP");
		alpha.push_back("asdfghjklASDFGHJKL");
		alpha.push_back("zxcvbnmZXCVBNM");
		vector<string> rtn;
		for (int i = 0; i<words.size(); i++)
		{
			int list = 0;
			if (find(alpha[0].begin(), alpha[0].end(), words[i][0]) != alpha[0].end())
			{
				list = 0;
			}
			else if (find(alpha[1].begin(), alpha[1].end(), words[i][0]) != alpha[1].end())
			{
				list = 1;
			}
			else if (find(alpha[2].begin(), alpha[2].end(), words[i][0]) != alpha[2].end())
			{
				list = 2;
			}

			bool flag = true;
			for (int j = 1;j<words[i].size();j++)
			{
				if (find(alpha[list].begin(), alpha[list].end(), words[i][j]) == alpha[list].end())
				{
					flag = false;
					break;
				}
			}
			if (flag)
				rtn.push_back(words[i]);
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.findWords(vector<string> {"Hello", "Alaska", "Dad", "Peace"});

	return 0;
}