#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		if (wall.size() <= 0)
			return 0;
		if (wall[0].size() <= 0)
			return 0;

		unordered_map<int, int> storage;
		vector<vector<int>> copy;
		for (auto iter_x : wall)
		{
			vector<int> to_insert;
			for (auto iter_y = iter_x.begin(); iter_y+1 != iter_x.end(); iter_y++)
			{
				if (to_insert.size() == 0)
					to_insert.push_back(*iter_y);
				else
					to_insert.push_back(*iter_y + to_insert.back());
				storage[to_insert.back()]++;
			}
			copy.push_back(to_insert);
		}

		int max = 0;
		int max_num = 0;
		for (auto iter = storage.begin(); iter != storage.end(); iter++)
		{
			if (iter->second > max)
			{
				max = iter->second;
				max_num = iter->first;
			}
		}

		int rtn = 0;
		for (auto iter : copy)
		{
			if (count(iter.begin(), iter.end(), max_num) == 0)
				rtn++;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	vector<vector<int>> wall;
	wall.push_back(vector<int>{1, 2, 2, 1});
	wall.push_back(vector<int>{3, 1, 2});
	wall.push_back(vector<int>{1, 3, 2});
	wall.push_back(vector<int>{2, 4});
	wall.push_back(vector<int>{3, 1, 2});
	wall.push_back(vector<int>{1, 3, 1, 1});
	x.leastBricks(wall);
}