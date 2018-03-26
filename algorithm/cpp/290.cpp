#include <map>


class Solution {
private:
	map<char, string> pat_case;
	map<string, char> pat_case2;
	vector<string> str_case;
public:
	bool wordPattern(string pattern, string str) {
		string tmp;
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i] == ' ')
			{
				if (!tmp.empty())
					str_case.push_back(tmp);
				tmp.clear();
			}
			else
			{
				tmp.push_back(str[i]);
			}
		}
		if (!tmp.empty())
			str_case.push_back(tmp);
		if (pattern.size() != str_case.size()) return false;
		for (int i = 0; i<pattern.size(); i++)
		{
			if (pat_case.find(pattern[i]) == pat_case.end())
			{
				if (pat_case2.find(str_case[i]) == pat_case2.end())
				{
					pat_case.insert({ pattern[i], str_case[i] });
					pat_case2.insert({ str_case[i],pattern[i] });
				}
				else
					return false;
			}
			else {
				if (pat_case[pattern[i]] != str_case[i])
					return false;
			}
		}
		return true;
	}
};