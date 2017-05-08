class Solution {
private:
	int mapx[26];
public:
	bool canConstruct(string ransomNote, string magazine) {
		for (int i = 0; i<26; i++)
			mapx[i] == 0;
		for (auto iter = magazine.begin(); iter != magazine.end(); iter++)
			mapx[int((*iter) - 'a')]++;
		for (auto iter = ransomNote.begin(); iter != ransomNote.end(); iter++)
		{
			mapx[int((*iter) - 'a')]--;
			if (mapx[int((*iter) - 'a')] < 0)
				return false;
		}
		return true;
	}
};