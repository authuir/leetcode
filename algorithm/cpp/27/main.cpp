#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {

		for (vector<int>::iterator iter = nums.begin();iter != nums.end();)
		{
			if (val == (*iter))
				iter = nums.erase(iter);
			else
				iter++;
		}
		return nums.size();
	}
};

int main(int argc, char * argv[])
{
	Solution x;

	vector<int> input;
	/*input.push_back(1);
	input.push_back(1);
	input.push_back(3);*/

	cout << x.removeElement(input,3) << endl;
	return 0;
}
