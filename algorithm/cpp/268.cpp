
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int size = nums.size() + 1;
		if (size == 1) return 0;
		int * da = new int[size];
		for (int i = 0; i<size; i++)
			da[i] = i;
		for (int i = 0; i<size - 1; i++)
			da[nums[i]] = -1;
		for (int i = 0; i<size; i++)
			if (da[i] != -1) return da[i];
		return 0;
	}
};