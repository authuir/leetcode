#include <iostream>
#include <vector>
using namespace std;

#define min(x,y) ((x)>(y)?(y):(x))

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		cost.push_back(0);
		for (int i = 0;i<cost.size(); i++)
			this->val.push_back(-1);
		return get(cost, cost.size() - 1);
	}
private:
	vector<int> val;
	int get(vector<int>& cost, int n)
	{
		if (this->val[n] != -1)
			return this->val[n];
		if (n == 0)
			return cost[0];
		else if (n == 1)
			return cost[1];
		else
		{
			this->val[n] = min(get(cost, n - 1), get(cost, n - 2)) + cost[n];
			return this->val[n];
		}
	}
};


int main()
{
	vector<int> value = { 0,0,1,1 };
	Solution x;
	cout << x.minCostClimbingStairs(value);
	return 0;
}
