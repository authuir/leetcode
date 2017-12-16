#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> rtn;
		if (matrix.size() <= 0)
			return rtn;
		if (matrix[0].size() <= 0)
			return rtn;

		bool flag = true;
		for (int i = 0;;i++)
		{
			if (!flag)
				for (int j = 0;j <= i; j++)
				{
					int x = j;
					int y = i - j;
					
					if (x < matrix.size() && y < matrix[0].size())
						rtn.push_back(matrix[x][y]);
					else if (x >= matrix.size() && y >= matrix[0].size())
						return rtn;
				}
			else
				for (int j = i;j >= 0; j--)
				{
					int x = j;
					int y = i - j;
					
					if (x < matrix.size() && y < matrix[0].size())
						rtn.push_back(matrix[x][y]);
					else if (x >= matrix.size() && y >= matrix[0].size())
							return rtn;
				}
			flag = !flag;
		}
	}
};

int main()
{
	Solution x;
	vector<vector<int>> matrix;
	matrix.push_back(vector<int>{1, 2, 3});
	matrix.push_back(vector<int>{4, 5, 6});
	matrix.push_back(vector<int>{7, 8, 9});

	x.findDiagonalOrder(matrix);

	return 0;
}