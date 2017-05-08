#include<iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> rev;
public:
	string reverseVowels(string s) {
		string rtn = s;
		for (int iter = s.size() - 1;iter >= 0;iter--)
		{
			switch (s[iter]) {
			case 'a': rev.push_back(iter);break;
			case 'e': rev.push_back(iter);break;
			case 'i': rev.push_back(iter);break;
			case 'o': rev.push_back(iter);break;
			case 'u': rev.push_back(iter);break;
			case 'A': rev.push_back(iter);break;
			case 'E': rev.push_back(iter);break;
			case 'I': rev.push_back(iter);break;
			case 'O': rev.push_back(iter);break;
			case 'U': rev.push_back(iter);break;
			default: break;
			}
		}
		int size = rev.size();
		for (int i = 0; i<size / 2; i++)
		{
			char tmp = rtn[rev[i]];
			rtn[rev[i]] = rtn[rev[size - i - 1]];
			rtn[rev[size - i - 1]] = tmp;
		}
		return rtn;
	}
};


int main()
{
	Solution s;
	s.reverseVowels("hello");
	return 0;
}