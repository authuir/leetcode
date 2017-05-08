#include<iostream>
#include<string>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		map<int, double> M;
		if (n >= 0)
		{
			double rtn = 1.0;
			bool ox = false;
			for (unsigned int i = 0,old_i=-1; i<n; )
			{
				if (ox)
					rtn = M[old_i]* M[old_i];
				else
					rtn = x*rtn;

				M.insert(map<int, double> ::value_type(i,rtn));
				if (rtn == 0) break;
				old_i = i;
				if (i*i < n && i>2) { i = i*i;ox = true; }
				else { i++;ox = false; }
			}
			return rtn;
		}
		else
		{
			double rtn = 1.0;
			for (int i = 0; i<abs(n); i++)
			{
				rtn = rtn / x;
				if (rtn == 0) break;
			}
			return rtn;
		}
	}
};

int main()
{
	Solution s;
	cout << s.myPow(1, 2147483647);
	return 0;
}