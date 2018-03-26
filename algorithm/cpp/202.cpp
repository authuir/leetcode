#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
	map<int, bool> stash;

	vector<int> get_v(int n)
	{
		vector<int> rtn;
		while (n>=10)
		{
			rtn.push_back(n%10);
			n = n / 10;
		}
		rtn.push_back(n);
		return rtn;
	}

public:
	bool isHappy(int n) {
		vector<int> rx;
		stash.clear();
		int temp;
		while (n != 1)
		{
			if (stash.find(n) != stash.end())
				return false;
			stash.insert({ n, true });
			
			rx = get_v(n);
			temp = 0;
			for (auto iter = rx.begin(); iter != rx.end(); iter++)
			{
				temp += (*iter)*(*iter);
			}
			n = temp;
		}
		return true;
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	cout << x.isHappy(19) << endl;
	cout << x.isHappy(100) << endl;
	cout << x.isHappy(120) << endl;
	cout << x.isHappy(1000) << endl;
	return 0;
}