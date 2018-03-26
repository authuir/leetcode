#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef pair<int, int> PAIR;

bool wayToSort(PAIR i, PAIR j) { return i.second > j.second; }

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> rtn;
		if (k <= 0 || nums.size() <= 0)
			return rtn;
		unordered_map<int, int> map;
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (map.find(*iter) == map.end())
			{
				map.insert(make_pair(*iter, 1));
				continue;
			} 
			else 
			{
				map[*iter] = map[*iter] + 1;
			}
		}

		vector<PAIR> tmp(map.begin(), map.end());
		sort(tmp.begin(), tmp.end(), wayToSort);

		for (int i = 0; i < k; i++)
		{
			rtn.push_back(tmp[i].first);
		}
		return rtn;
	}
};


int main()
{
	Solution x;
	x.topKFrequent(vector<int>{1, 1, 1, 2, 2, 3, 5}, 2);
	return 0;
}