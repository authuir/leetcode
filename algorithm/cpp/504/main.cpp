class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		string rtn;
		int xx = 0;
		if (num < 0) {
			rtn.push_back('-');
			num = 0 - num;
			xx = 1;
		}
		while (num >= 7)
		{
			rtn.insert(rtn.begin() + xx, char(num % 7) + '0');
			num = num / 7;
		}
		if (num != 0)
			rtn.insert(rtn.begin() + xx, char(num) + '0');

		return rtn;
	}
};