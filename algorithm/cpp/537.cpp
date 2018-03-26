#include <iostream>
#include <sstream>
using namespace std;

struct complex{
	int a;
	int b;
} ;
complex operator*(const complex &left, const complex &right)
{
	complex rtn;
	rtn.a = left.a*right.a - left.b*right.b;
	rtn.b = left.a*right.b + left.b*right.a;
	return rtn;
}

class Solution {
private:

	string r_trans(complex x)
	{
		stringstream newstr;
		newstr << x.a <<"+" <<x.b <<"i";
		return newstr.str();
	}
	complex trans(string str)
	{
		int a = str.find_first_of('+', 0);
		int b = str.find_first_of('i', 0);
		string aa, bb;
		aa.assign(str.begin(), str.begin() + a);
		bb.assign(str.begin()+a+1, str.begin() + b);
		complex rtn;
		rtn.a = atoi(aa.c_str());
		rtn.b = atoi(bb.c_str());
		return rtn;
	}
public:
	string complexNumberMultiply(string a, string b) {
		complex left = trans(a);
		complex right = trans(b);
		return  r_trans(left*right);
	}
};

int main()
{
	Solution x;
	cout << x.complexNumberMultiply("1+1i", "1+1i");

	return 0;
}