#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int size = numbers.size();
		vector<int> rtn;
		if (size <= 1) return rtn;
		for (int l1 = 0; l1 < size - 1; l1++)
		{
			for (int l2 = l1+1; l2 < size; l2++)
			{
				if (numbers[l1] + numbers[l2] == target)
				{
					rtn.push_back(l1+1); rtn.push_back(l2+1);
					return rtn;
				}
				else if (numbers[l1] + numbers[l2] > target)
					break;
			}
		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.twoSum(vector<int>{0, 1, 2, 3}, 4)[0];
	return 0;
}