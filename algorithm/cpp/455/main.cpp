#include <algorithm>

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		if (s.size() <= 0 || g.size() <= 0) return 0;

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int rtn = 0;
		auto iters = s.begin();
		for (auto iterg = g.begin(); iterg != g.end(); iterg++)
		{
			while (iters != s.end())
			{
				if ((*iters) >= (*iterg))
				{
					rtn++;
					iters++;
					break;
				}
				else
				{
					iters++;
				}
			}
			if (iters == s.end())
				break;
		}
		return rtn;
	}
};