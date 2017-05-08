class Solution {
public:
	bool checkRecord(string s) {
		bool rtn = true;
		int cnt_A = 0;
		int cnt_L = 0;
		int state_L = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == 'A')
			{
				cnt_A++;
				state_L = 0;
			}
			else if (s[i] == 'L')
			{
				if (state_L >= 2)
					cnt_L++;
				else
					state_L++;
			}
			else
				state_L = 0;

		}
		if (cnt_A>1 || cnt_L >= 1)
			rtn = false;
		return rtn;
	}
};