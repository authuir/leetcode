#include <iostream>
using namespace std;

class Solution {
private:
	int alpha[26];
public:
	bool isAnagram(string s, string t) {
		for (int i = 0; i<26; i++) alpha[i] = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++)
			alpha[int(*iter - 'a')]++;
		for (auto iter = t.begin(); iter != t.end(); iter++)
			alpha[int(*iter - 'a')]--;
		for (int i = 0; i<26; i++)
			if (alpha[i] != 0)
				return false;
		return true;

	}
};