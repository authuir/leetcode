#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	// return nums of Mine arround
	int haveMineArround(vector<vector<char>>& board, vector<int>& click)
	{
		int rtn = 0;
		vector<int> x_all = { click[0] - 1, click[0], click[0] + 1 };
		vector<int> y_all = { click[1] - 1, click[1], click[1] + 1 };
		for (auto i = x_all.begin(); i != x_all.end(); i++)
			for (auto j = y_all.begin(); j != y_all.end(); j++)
			{
				if (*i < 0 || *j < 0 || *i >= board.size() || *j >= board[0].size())
					continue;
				if (board[*i][*j] == 'M')
					rtn++;
			}
		return rtn;
	}

	vector<vector<char>> recursive(vector<vector<char>>& board, vector<int>& click) {
		if (click[0] < 0 || click[1] < 0 || click[0] >= board.size() || click[1] >= board[0].size())
			return board;
		if (board[click[0]][click[1]] != 'E')
			return board;

		int mines_arround = haveMineArround(board, click);

		if (mines_arround != 0)
		{
			board[click[0]][click[1]] = mines_arround + '0';
			return board;
		}
		else
		{
			board[click[0]][click[1]] = 'B';
		}

		click[0]++; board = recursive(board, click); click[0]--;
		click[1]++; board = recursive(board, click); click[1]--;
		click[1]--; board = recursive(board, click); click[1]++;
		click[0]--; board = recursive(board, click); click[0]++;


		click[0]++; click[1]++; board = recursive(board, click); click[0]--; click[1]--;
		click[0]++; click[1]--; board = recursive(board, click); click[0]--; click[1]++;
		click[0]--; click[1]++; board = recursive(board, click); click[0]++; click[1]--;
		click[0]--; click[1]--; board = recursive(board, click); click[0]++; click[1]++;
		return board;
	}


public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}

		return recursive(board, click);
	}
};


int main()
{
	Solution x;

	//vector<vector<char>> input = vector<vector<char>>{ 
	//	vector<char>{'B','B','B','B','B','B','1','E'},
	//	vector<char>{'B','1','1','1','B','B','1','M'},
	//	vector<char>{'1','2','M','1','B','B','1','1'},
	//	vector<char>{'M','2','1','1','B','B','B','B'},
	//	vector<char>{'1','1','B','B','B','B','B','B'},
	//	vector<char>{'B','B','B','B','B','B','B','B'},
	//	vector<char>{'B','1','2','2','1','B','B','B'},
	//	vector<char>{'B','1','M','M','1','B','B','B'}
	//};

	//vector<vector<char>> input = vector<vector<char>>{
	//	vector<char>{'E', 'E', 'E', 'E', 'E'},
	//	vector<char>{'E', 'E', 'M', 'E', 'E'},
	//	vector<char>{'E', 'E', 'E', 'E', 'E'},
	//	vector<char>{'E', 'E', 'E', 'E', 'E'}
	//};

	vector<vector<char>> input = vector<vector<char>>{
		vector<char>{'E','E','E','E','E','E','E','E'},
		vector<char>{'E','E','E','E','E','E','E','M'},
		vector<char>{'E','E','M','E','E','E','E','E'},
		vector<char>{'M','E','E','E','E','E','E','E'},
		vector<char>{'E','E','E','E','E','E','E','E'},
		vector<char>{'E','E','E','E','E','E','E','E'},
		vector<char>{'E','E','E','E','E','E','E','E'},
		vector<char>{'E','E','M','M','E','E','E','E'}
	};

	//vector<vector<char>> input = vector<vector<char>>{
	//	vector<char>{'B', '1', 'E', '1', 'B'},
	//	vector<char>{'B', '1', 'M', '1', 'B'},
	//	vector<char>{'B', '1', '1', '1', 'B'},
	//	vector<char>{'B', 'B', 'B', 'B', 'B'}
	//};

	vector<vector<char>> output = x.updateBoard(input, vector<int>{0,0});
	return 0;
}
