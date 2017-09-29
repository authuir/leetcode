class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> rtn;
		bool is_up = true;
		if (k >= n || k<1)
			return rtn;
		int local = 1;
		rtn.push_back(local);
		for (int i = k; i>0; i--)
		{
			if (is_up)
				local = local + i;
			else
				local = local - i;
			rtn.push_back(local);
			is_up = !is_up;
		}
		for (int i = 1; i<n - k; i++)
		{
			rtn.push_back(k + i + 1);
		}
		return rtn;
	}
};