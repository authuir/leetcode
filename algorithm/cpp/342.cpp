
class Solution {
public:
	bool isPowerOfFour(int n) {
		if (n <= 0) return false;
		int cnt = 0;
		for (int i = 0; i<32; i++)
		{
			if (i % 2 == 0)
			{
				if ((n & 0x01) == 0x01)
					cnt++;
			}
			else 
			{
				if ((n & 0x01) == 0x01)
					return false;
			}
			n = n >> 1;
		}
		if (cnt == 1)
			return true;
		return false;
	}
};

int main()
{
	Solution x;
	x.isPowerOfFour(3);
}