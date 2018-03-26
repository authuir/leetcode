#include <iostream>
#include <string>
using namespace std;

static char * c[4][10] = {
	{ "","I","II","III","IV","V","VI","VII","VIII","IX" }, //I,V
	{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" }, //X,L
	{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" }, //D,C
	{ "","M","MM","MMM","FF","FF","FF","FF","FF","FF" }	   //M
};

class Solution {
public:
	int romanToInt(string s) {
		int len = s.length();
		int xc = -1;
		if (len <= 0) return 0;
		switch (s[0])
		{
		case 'M':xc = 3;
			break;
		case 'D':xc = 2;
			break;
		case 'C':xc = 2;
			break;
		case 'X':xc = 1;
			break;
		case 'L':xc = 1;
			break;
		case 'I':xc = 0;
			break;
		case 'V':xc = 0;
			break;
		default:
			return 0;
		}
		for (int i = 9;i >= 1; i--)
		{
			if (s.substr(0, strlen(c[xc][i])).compare(c[xc][i]) == 0)
			{
				return pow(10,xc)*i + romanToInt(s.erase(0,strlen(c[xc][i])));
			}
		}
		return 0;
	}
};

int main(int argc, char * argv[])
{
	Solution solu;
	cout << solu.romanToInt("MMM") << endl;
	cout << solu.romanToInt("MMMCMXCIX") << endl;
	cout << solu.romanToInt("MCD") << endl;
	cout << solu.romanToInt("MD") << endl;
	cout << solu.romanToInt("MDC") << endl;
	cout << solu.romanToInt("MCMLXXXIV") << endl;
	cout << solu.romanToInt("MDCCCXCIX") << endl;
	cout << solu.romanToInt("XCIII") << endl;
	cout << solu.romanToInt("CMXCIX") << endl;
}