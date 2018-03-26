#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string rtn;
		n--;
		while (n >= 0)
		{
			if (n < 26)
			{
				rtn.insert(rtn.begin(), 'A' + n);
				break;
			}
			else
			{
				rtn.insert(rtn.begin(), 'A' + n % 26);
				n = n / 26 - 1;
			}
		}
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.convertToTitle(52)[0] << x.convertToTitle(52)[1];
	return 0;
}