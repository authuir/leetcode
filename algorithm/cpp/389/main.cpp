class Solution {
private:
	int mapx[26];
public:
	char findTheDifference(string s, string t) {
		for (int i = 0; i<26; i++)
			mapx[i] = 0;
		for (auto iter = t.begin(); iter != t.end(); iter++)
		{
			mapx[int((*iter) - 'a')]++;
		}
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			mapx[int((*iter) - 'a')]--;
		}
		for (int i = 0; i<26; i++)
		{
			if (mapx[i] == 1)
				return char(i + 'a');
		}
		return -1;
	}
};