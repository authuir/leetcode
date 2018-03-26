#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ws = 0;
		int rtn = 0;
		for (auto iter = s.end(); iter != s.begin();)
		{
			iter--;
			rtn += (*iter - 'A' + 1) * pow(26,ws);
			cout << *iter;
			ws++;
		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.titleToNumber("AB");
	return 0;
}