class Solution {
private:
	int bits(int num)
	{
		int rtn = 0;
		for (int i = 0; i<32; i++)
		{
			if ((num >> i) & 0x01 == 1)
				rtn++;
		}
		return rtn;
	}


public:
	vector<int> countBits(int num) {
		vector<int> rtn;
		for (int i = 0; i <= num; i++)
		{
			rtn.push_back(bits(i));
		}
		return rtn;
	}
};