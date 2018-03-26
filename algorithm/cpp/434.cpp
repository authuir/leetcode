class Solution {
public:
	int countSegments(string s) {
		if (s == "") return 0;
		int flag_new = 1;//1:前面一个是空格, 0:前面一个是字符
		int rtn = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			switch (flag_new)
			{
			case 1: {
				if (*iter != ' ')
				{
					rtn++;
					flag_new = 0;
				}
				break;
			}
			case 0: {
				if (*iter == ' ')
				{
					flag_new = 1;
				}
				break;
			}
			}
		}
		return rtn;
	}
};