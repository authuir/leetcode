#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool less_second(const vector<int> & m1, const vector<int> & m2) {
	if (m1[1] == m2[1])
		return m1[0] < m2[0];
	else
		return m1[1] < m2[1];
}

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {

		if (pairs.size() == 0)
			return 0;
		if (pairs.size() == 1)
			return 1;

		sort(pairs.begin(), pairs.end(), less_second);

		for (auto iter = pairs.begin()+1; iter != pairs.end(); )
		{
			if ((*iter)[0] <= (*(iter - 1))[1])
			{
				iter = pairs.erase(iter);
				if (iter == pairs.end())
					break;
			}
			else
				iter++;
		}
		return pairs.size();
	}
};

int main()
{
	vector<vector<int>> pairs;

	pairs.push_back(vector<int>{-6, 9});
	pairs.push_back(vector<int>{1, 6});
	pairs.push_back(vector<int>{8, 10});
	pairs.push_back(vector<int>{-1, 4});
	pairs.push_back(vector<int>{-6, -2});
	pairs.push_back(vector<int>{-9, 8});
	pairs.push_back(vector<int>{-5, 3});
	pairs.push_back(vector<int>{0, 3});

	Solution x;
	cout<<x.findLongestChain(pairs);

	return 0;
}