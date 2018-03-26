class Solution {
private:
	int mapx[26];
public:
	int firstUniqChar(string s) {
		for (int i = 0; i<26; i++)
		{
			mapx[i] = 0;
		}
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			mapx[int((*iter) - 'a')]++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (mapx[int(s[i] - 'a')] == 1)
				return (i);
		}
		return -1;
	}
};