#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct loc {
	int x;
	int y;
};

bool operator==(const loc & l1, const loc & l2)
{
	if (l1.x == l2.x && l1.y == l2.y)
		return true;
	return false;
}

class Solution {
private :
	bool isClose(const vector<loc> &sets, loc l)
	{
		if (l.x > 0)
		{
			l.x--;
			auto iter = find(sets.begin(), sets.end(), l);
			if (iter != sets.end())
			{
				return true;
			}
			l.x++;
		}
		if (l.y > 0)
		{
			l.y--;
			auto iter = find(sets.begin(), sets.end(), l);
			if (iter != sets.end())
			{
				return true;
			}
			l.y++;
		}
		return false;
	}

	vector<vector<loc>> battles;

	void insertBattles(loc input)
	{
		vector<vector<loc>>::iterator tm = battles.end();
		bool flag = true;
		for (auto sets = battles.begin(); sets != battles.end(); sets++)
		{
			if (isClose(*sets, input))
			{
				flag = false;
				if (tm == battles.end())
				{
					tm = sets;
					(*tm).push_back(input);
				}
				else
				{
					for (auto iter : *sets)
					{
						(*tm).push_back(iter);
					}
					sets = battles.erase(sets);
					if (sets == battles.end())
						break;
				}
			}
		}
		if (flag)
		{
			battles.push_back(vector<loc>{ input });
		}
	}

public:
	int countBattleships(vector<vector<char>>& board) {
		int size_vertical = board.size();
		if (size_vertical == 0) return 0;
		int size_horizontal = board[0].size();
		for (int i = 0; i < size_vertical; i++)
		{
			for (int j = 0; j < size_horizontal; j++)
			{
				if (board[i][j] == 'Xs')
				{
					loc tmp;
					tmp.x = i;
					tmp.y = j;
					insertBattles(tmp);
				}
			}
		}
		return battles.size();
	}
};

int main()
{
	Solution x;
	vector<vector<char>> tmp = {
		vector<char>{'X','.','.','X'},
		vector<char>{'X','X','X','X'},
		vector<char>{'.','.','.','X'}
	};
	cout << x.countBattleships(tmp);
	return 0;
}