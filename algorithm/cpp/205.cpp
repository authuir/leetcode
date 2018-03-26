#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
	map<char, char> stc,stc2;
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;
		for (int i = 0; i < s.size(); i++)
		{
			if (stc.find(s[i]) == stc.end() && stc2.find(t[i])==stc2.end())
			{
				stc.insert({ s[i],t[i] });
				stc2.insert({ t[i],s[i] });
			}
			else
			{
				if (stc[s[i]] != t[i] || stc2[t[i]] != s[i])
					return false;
			}
		}
		return true;
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	cout << x.isIsomorphic("ab","aa");
	return 0;
}