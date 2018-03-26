#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> rtn;
		if (p.size() > s.size()) return rtn;
		int size = s.size() - p.size() + 1;
		for (int i = 0; i<size; i++)
		{
			string tmp;
			tmp.assign(s.begin() + i, s.begin() + (i + p.size()));
			int tmpca[26] = { 0 };
			for (int j = 0; j<tmp.size(); j++)
			{
				tmpca[int(tmp[j] - 'a')]++;
				tmpca[int(p[j] - 'a')]--;
			}
			int tx = 0;
			for (int j = 0; j<26; j++)
			{
				if (tmpca[j] != 0)
				{
					tx = 1;
					break;
				}
			}
			if (tx == 0)
			{
				rtn.push_back(i);
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.findAnagrams("cbaebabacd", "abc");
	return 0;
}