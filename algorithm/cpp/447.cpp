#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	int jc(int n)
	{
		int j = 1;
		for (int i = 1;i <= n;i++)
			j *= i;
		return j;
	}

public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() <= 1) return 0;
		int rtn = 0;
		for (int i = 0; i<points.size(); i++)
		{
			map<int, int> counter;
			//vector<int> counter;
			for (int j = 0; j<points.size(); j++)
			{
				if (i == j)continue;
				int dis = (points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second);
				if (counter.find(dis) == counter.end())
				{
					counter.insert({ dis,1 });
				}
				else
				{
					counter[dis]++;
				}
			}

			for (auto my_Itr = counter.begin(); my_Itr != counter.end(); ++my_Itr)
			{
				if ((my_Itr->second) <= 1)
					continue;
				else
				{
					rtn += jc(my_Itr->second) / jc(my_Itr->second - 2);
				}
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.numberOfBoomerangs(vector<pair<int, int>> { {0, 0}, { 1,0 }, { 2,0 } });

	return 0;
}