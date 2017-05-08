#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (int i = 0;i < s.length();i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stk.push(s[i]);
			else if (s[i] == ')')
			{
				if (stk.empty())return false;
				if (stk.top() != '(')
					return false;
				stk.pop();
			}
			else if (s[i] == ']')
			{
				if (stk.empty())return false;
				if (stk.top() != '[')
					return false;
				stk.pop();
			}
			else if (s[i] == '}')
			{
				if (stk.empty())return false;
				if (stk.top() != '{')
					return false;
				stk.pop();
			}
		}
		if (stk.size() != 0)
		{
			return false;
		}
		return true;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.isValid("]")<<endl;
	return 0;
}
