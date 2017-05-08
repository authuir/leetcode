#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
private:
	vector<char> alpha = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	char p[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	//搞清楚类成员变量初始化的问题
public:

	string toHex(int num) {
		string rtn;
		unsigned int tp = num;
		if (num == 0) return "0";
		int flag = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (flag == 0)
			{
				if (((tp >> (i * 4)) & 0xf) != 0)
				{
					rtn.push_back(alpha[((tp >> (i * 4)) & 0xf)]);
					flag = 1;
				}
			}
			else
			{
				rtn.push_back(alpha[((tp >> (i * 4)) & 0xf)]);
			}
		}
		return rtn;
	}
};

int main()
{
	Solution  x;
	cout << x.toHex(16);
	return 0;
}