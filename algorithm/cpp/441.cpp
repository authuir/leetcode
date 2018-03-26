class Solution {
public:
	int arrangeCoins(int n) {
		int rtn = 0;
		while (n > rtn)
		{
			rtn++;
			n = n - rtn;
		}
		return rtn;
	}
};