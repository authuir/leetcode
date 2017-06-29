#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool isBiger(const pair<char, int> & s1, const pair<char, int> & s2)
{
	return (s1.second > s2.second);
}

class Solution {
public:
	string frequencySort(string s) {
		string rtn = "";
		map<char, int> tmp;
		if (s.size() <= 0)
			return rtn;
		for (auto iter : s)
		{
			if (tmp.find(iter) == tmp.end())
			{
				tmp[iter] = 1;
			}
			else
			{
				tmp[iter] = tmp[iter] + 1;
			}
		}
		vector<pair<char, int>> vtMap;
		for (auto it = tmp.begin(); it != tmp.end(); it++)
			vtMap.push_back(make_pair(it->first, it->second));
		sort(vtMap.begin(), vtMap.end(), isBiger);
		for (auto iter = vtMap.begin(); iter != vtMap.end(); iter++)
		{
			rtn += string(iter->second, iter->first);
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.frequencySort("AdsAbbbb");
	return 0;
}