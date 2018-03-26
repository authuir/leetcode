class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		while (true)
		{
			if (n<3)
				break;
			if (n % 3 != 0)
				return false;
			if (n<3)
				break;
			n = n / 3;
		}
		if (n == 1)
			return true;
		return false;
	}
};