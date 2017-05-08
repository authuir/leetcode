class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.size() <= 0) return 0;
		if (grid[0].size() <= 0) return 0;
		int width = grid[0].size();
		int height = grid.size();

		int rtn = 0;

		for (int i = 0; i<height; i++)
			for (int j = 0; j<width; j++)
			{
				if (grid[i][j] == 1)
				{
					if (i - 1 >= 0)
					{
						if (grid[i - 1][j] == 0) rtn++;
					}
					else
						rtn++;
					if (j - 1 >= 0)
					{
						if (grid[i][j - 1] == 0) rtn++;
					}
					else
						rtn++;
					if (i + 1 <height)
					{
						if (grid[i + 1][j] == 0) rtn++;
					}
					else
						rtn++;
					if (j + 1 <width)
					{
						if (grid[i][j + 1] == 0) rtn++;
					}
					else
						rtn++;
				}
			}
		return rtn;
	}
};