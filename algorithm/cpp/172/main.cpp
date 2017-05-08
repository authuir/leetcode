class Solution {
public:
	int trailingZeroes(int n) {
		int res;
		while (n > 0)
		{
			res += n / 5;
			n = n / 5;
		}
	}
};

int main()
{
	return 0;
}