#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
	map<int, int> dataset;

public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		auto iter = dataset.find(n);
		if (iter != dataset.end())
			return iter->second;
		int r1 = climbStairs(n - 1);
		int r2 = climbStairs(n - 2);

		dataset.insert(map<int, int>::value_type(n - 1, r1));
		dataset.insert(map<int, int>::value_type(n - 2, r2));

		return r1+r2;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	std::cout << s.climbStairs(2) << std::endl;
	std::cout << s.climbStairs(5) << std::endl;
	std::cout << s.climbStairs(44) << std::endl;
	std::cout << s.climbStairs(6) << std::endl;
	std::cout << s.climbStairs(10) << std::endl;
	return 0;
}
