#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		vector<int> mask(M.size(), -1);
		int count = 0;
		for (int i=0; i < M.size()-1; i++)
			for (int j = i + 1; j < M.size(); j++)
			{
				if (M[i][j] == 1)
				{
					cout << i << ',' << j << endl;
					if (mask[i] == -1 && mask[j] == -1)
					{
						mask[i] = count;
						mask[j] = count;
						count++;
					}
					else if (mask[i] != -1 && mask[j] != -1)
					{
						int mask_j = mask[j];
						for (int k = 0; k < mask.size(); k++)
						{
							if (mask[k] == mask_j)
								mask[k] = mask[i];
						}
					}
					else
					{
						if (mask[i] == -1)
							mask[i] = mask[j];
						else
							mask[j] = mask[i];
					}
				}
			}
		vector<int> x(count, -1);
		int rtn = 0;
		for (int k = 0; k < mask.size(); k++)
		{
			if (mask[k] == -1)
				rtn++;
			else
			{
				if (x[mask[k]] == -1)
				{
					x[mask[k]] = 0;
					rtn++;
				}
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;

	vector<vector<int>> input = {
		vector<int>{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
		vector<int>{1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		vector<int>{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		vector<int>{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		vector<int>{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		vector<int>{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		vector<int>{0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
		vector<int>{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 1, 1}
	};

	x.findCircleNum(input);

	return 0;
}
