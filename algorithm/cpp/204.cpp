#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
	int target = 0;
	int * hashmap = NULL;

public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		int rtn = 1;
		target = sqrt(n);
		hashmap = new int[n];
		for (int i = 0; i < n; i++)
			hashmap[i] = -1;
		for (int i = 3; i < n; i+=2)
		{
			if (hashmap[i]==-1)
			{
				rtn++;
				cout << i << endl;
				if (i > target) continue;
				for (int j = i*i; j<n; j += i) {
					hashmap[j] = 0;
				}
			}
		}
		return rtn;
	}
};

int main(int argc, char* argv[])
{
	Solution x;
	cout << x.countPrimes(1500000);
	return 0;
}