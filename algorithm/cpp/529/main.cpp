#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<char>> board_indicator;

	vector<vector<char>> search(vector<vector<char>>& board, vector<int>& click) {
		if (board_indicator[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}
		if (board_indicator[click[0]][click[1]] >= '0' && board_indicator[click[0]][click[1]] <= '8')
		{
			board[click[0]][click[1]] = board_indicator[click[0]][click[1]];
			return board;
		}
		if (board_indicator[click[0]][click[1]] == 'E')
		{
			board[click[0]][click[1]] = 'B';
			vector<int> i_x = { click[0] - 1, click[0], click[0] + 1 };
			vector<int> i_y = { click[1] - 1, click[1], click[1] + 1 };
			for (auto iter_x : i_x)
				for (auto iter_y : i_y)
				{
					if (iter_x < 0 || iter_x >= board.size())
						continue;
					if (iter_y < 0 || iter_y >= board[0].size())
						continue;
					if (iter_x == click[0] && iter_x == click[1])
						continue;

					if (board_indicator[iter_x][iter_y] >= '0' && board_indicator[iter_x][iter_y] <= '8')
					{
						board[iter_x][iter_y] = board_indicator[iter_x][iter_y];
					}
					else if (board_indicator[iter_x][iter_y] == 'E' && board[iter_x][iter_y] != 'B')
					{
						board[iter_x][iter_y] = 'B';
						vector<int> tmp = vector<int>{iter_x, iter_y};
						search(board, tmp);
					}
				}
		}
		return board;
	}

public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (click.size() != 2)
			return board;
		board_indicator = board;
		for (int x = 0; x<board.size(); x++)
			for (int y = 0; y<board.size(); y++)
			{
				if (board[x][y] != 'M')
					continue;
				if (board[x][y] == 'M')
				{
					vector<int> i_x = { x - 1, x, x + 1 };
					vector<int> i_y = { y - 1, y, y + 1 };
					for (auto iter_x : i_x)
						for (auto iter_y : i_y)
						{
							if (iter_x < 0 || iter_x >= board.size())
								continue;
							if (iter_y < 0 || iter_y >= board[0].size())
								continue;
							if (board_indicator[iter_x][iter_y] == 'E')
							{
								board_indicator[iter_x][iter_y] = '1';
							}
							else if (board_indicator[iter_x][iter_y] >= '0' && board_indicator[iter_x][iter_y] < '8' )
							{
								board_indicator[iter_x][iter_y]++;
							}
						}
				}
			}
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board.size(); y++)
			{
				cout << board_indicator[x][y] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		search(board, click);
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board.size(); y++)
			{
				cout << board[x][y] << ' ';
			}
			cout << endl;
		}

		return board;
	}
};

int main()
{
	Solution x;
	vector<vector<char>> input = vector<vector<char>>{ 
		vector<char>{'B','B','B','B','B','B','1','E'},
		vector<char>{'B','1','1','1','B','B','1','M'},
		vector<char>{'1','2','M','1','B','B','1','1'},
		vector<char>{'M','2','1','1','B','B','B','B'},
		vector<char>{'1','1','B','B','B','B','B','B'},
		vector<char>{'B','B','B','B','B','B','B','B'},
		vector<char>{'B','1','2','2','1','B','B','B'},
		vector<char>{'B','1','M','M','1','B','B','B'}
	};
	x.updateBoard(input, vector<int>{0,7});
	return 0;
}