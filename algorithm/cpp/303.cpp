class NumArray {
private:
	int* data;
	int cnt;

public:
	NumArray(vector<int> nums) {
		cnt = nums.size();
		data = new int[cnt];
		for (int i = 0; i<cnt; i++)
			data[i] = nums[i];
	}

	int sumRange(int i, int j) {
		if (i>j) return NULL;
		if (i<0) return NULL;
		if (j >= cnt) return NULL;
		int sum = 0;
		for (; i <= j; i++)
		{
			sum = sum + data[i];
		}
		return sum;
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/