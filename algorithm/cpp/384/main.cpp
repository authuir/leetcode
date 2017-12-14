#include <random>

class Solution {
private:
	vector<int> origin;

public:
	Solution(vector<int> nums) {
		this->origin = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return this->origin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> rtn = this->origin;
		random_device rd;

		for (int i = 0; i < rtn.size(); i++)
		{
			int j = rd() % (rtn.size() - i) + i;
			int tmp = rtn[i];
			rtn[i] = rtn[j];
			rtn[j] = tmp;
		}

		return rtn;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/