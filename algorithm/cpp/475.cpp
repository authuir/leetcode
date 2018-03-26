#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	unsigned int findDisofCloseHeater(int posi, vector<int>& heaters)
	{
		unsigned int rtn = -1;
		bool grad = true;
		if (posi <= heaters.front()) return (heaters.front() - posi);
		if (posi >= heaters.back()) return (posi- heaters.back());

		for (auto iter = heaters.begin(); iter!=heaters.end(); iter++)
		{
			if (posi == *iter) return 0;
			else if (posi > *iter) rtn = posi - *iter;
			else if (posi < *iter) return min((*iter - posi), int(rtn));
		}

		return rtn;
	}
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (houses.size() <= 0) return 0;
		int rtn = 0;
		sort(heaters.begin(), heaters.end());

		for (int i=0; i<houses.size(); i++)
		{
			int tmpradius = findDisofCloseHeater(houses[i], heaters);
			if (rtn < tmpradius)
				rtn = tmpradius;
		}

		return rtn;
	}
};

int main()
{
	Solution x;
	x.findRadius(vector<int>{1, 2, 3, 5, 15}, vector<int>{2, 30});

	return 0;
}