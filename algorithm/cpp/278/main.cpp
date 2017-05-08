// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		unsigned int tmp, bon_l, bon_r;
		if (n == 1) return 1;
		bon_r = n;
		bon_l = 1;
		if (isBadVersion(bon_l)) return 1;
		while (true)
		{
			tmp = (bon_r + bon_l) / 2;

			if (isBadVersion(tmp))
			{
				if (tmp == (bon_l + 1))
					return tmp;
				else
					bon_r = tmp;
			}
			else
			{
				if ((tmp + 1) == bon_r)
					return bon_r;
				else
					bon_l = tmp;
			}
		}
		return 0;
	}
};