#include<iostream>
#include<string>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double rtn = 1.0;
        bool is_negative = (n < 0);        
        unsigned int nn = abs(n);
        while (nn > 0) {
            if (nn%2==1) rtn = rtn * x;
            nn = nn / 2;
            x = x*x;
        }
        if (is_negative)
            rtn = 1.0 / rtn;
        return rtn;
    }
}; 

int main()
{
	Solution s;
	cout << s.myPow(2.0, 10);
	return 0;
}