#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		int a = 0, b = 0, c = 0, d = 0;
		d = num % 10;
		c = (num / 10) % 10;
		b = (num / 100) % 10;
		a = (num / 1000) % 10;
		return a_arr[a] + b_arr[b] + c_arr[c] + d_arr[d];
	}
	Solution()
	{
		d_arr = vector<string>{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
		c_arr = vector<string>{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		b_arr = vector<string>{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		a_arr = vector<string>{ "","M","MM","MMM" };
	}
private:
	vector<string> a_arr;
	vector<string> b_arr;
	vector<string> c_arr;
	vector<string> d_arr;
};