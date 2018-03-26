class Solution {
public:
	string reverseString(string s) {
		string rtn;
		for (int iter = s.size() - 1;iter >= 0;iter--)
		{
			rtn.push_back(s[iter]);
		}
		return rtn;
	}
};