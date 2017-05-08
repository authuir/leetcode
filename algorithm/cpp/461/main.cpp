class Solution {
public:
	int hammingDistance(int x, int y) {
		int rtn = 0;
		for (int i = 0; i<32; i++)
		{
			if (((x >> i) & 0x01) != ((y >> i) & 0x01))
				rtn++;
		}
		return rtn;
	}
};