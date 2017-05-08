#include<iostream>
using namespace std;

int guess(int a)
{
	if (a == 6) return 0;
	else if (a > 6) return -1;
	return 1;
}
class Solution {
public:
	int guessNumber(int n) {
		unsigned long beg = 1;
		unsigned long las = n;

		if (guess(n) == 0) return n;
		if (guess(1) == 0) return 1;
		while (true)
		{
			unsigned long x = (beg + las) / 2;
			int a = guess(x);
			if (a == 0)
				return x;
			else if (a == -1)
			{
				las = x;
			}
			else
			{
				beg = x;
			}
		}
	}
};

int main()
{
	Solution x;
	

	cout << x.guessNumber(10);
	return 0;
}