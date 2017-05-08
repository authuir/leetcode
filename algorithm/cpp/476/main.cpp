class Solution {
public:
	int findComplement(int num) {
		bool started = false;
		int rtn = 0;
		for (int i = 31;i >= 0;i--)
		{
			if (started == false)
			{
				if ((num >> i) & 0x01 == 0x01)
				{
					started = true;
				}
			}
			else
			{
				rtn += (!((num >> i) & 0x01)) << i;
			}
		}
		return rtn;
	}
};