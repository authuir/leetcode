class Solution {
public:
	int addDigits(int num) {
		int rtn = 0;
		if (num >= 0 && num <10) return num;
		while (num != 0)
		{
			rtn = rtn + num % 10;
			num = (num) / 10;
		}
		if (rtn >= 0 && rtn <10) return rtn;
		else return (addDigits(rtn));
	}
};