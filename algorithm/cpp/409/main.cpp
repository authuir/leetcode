class Solution {
private:
	int upcase[26] = { 0 };
	int lowcase[26] = { 0 };

public:
	int longestPalindrome(string s) {
		if (s.size() == 0) return 0;

		int rtn = 0;
		bool is_os = false;

		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			if (int(*iter) >= int('a') && int(*iter) <= int('z'))
			{
				lowcase[int(*iter) - int('a')]++;
			}
			else if (int(*iter) >= int('A') && int(*iter) <= int('Z'))
			{
				upcase[int(*iter) - int('A')]++;
			}
		}

		for (int i = 0; i<26; i++)
		{
			if (upcase[i] == 0 && lowcase[i] == 0) continue;

			rtn += int(upcase[i] / 2) * 2;
			rtn += int(lowcase[i] / 2) * 2;

			if ((upcase[i] % 2) == 1 || (lowcase[i] % 2) == 1) is_os = true;

		}
		if (is_os)
			rtn++;
		return rtn;
	}
};