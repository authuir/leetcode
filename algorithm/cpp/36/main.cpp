#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<char>> rout;
		vector<char> tmp;
		
		int i = 0;
		
		for (vector<vector<char>>::iterator iter = board.begin();iter != board.end();iter++)
		{
			int zf[9] = { 0 };
			for (vector<char>::iterator fter = (*iter).begin();fter != (*iter).end();fter++)
			{
				
				if ((*fter) == '.') 
					continue;
				else if ((*fter) > '9' || (*fter) < '1')
					return false;
				else if (zf[(*fter) - '0' - 1] != 0)
					return false;
				else
					zf[(*fter) - '0' - 1]++;
			}
		}
		for (int si = 0;si < 9;si++)
		{
			int zf[9] = { 0 };
			for (vector<vector<char>>::iterator iter = board.begin();iter != board.end();iter++)
			{
				if ((*iter)[si] == '.')
					continue;
				else if ((*iter)[si] > '9' || (*iter)[si] < '1')
					return false;
				else if (zf[(*iter)[si] - '0' - 1] != 0)
					return false;
				else
					zf[(*iter)[si] - '0' - 1]++;
			}
		}


		
		for (int ii = 0; ii < 9; ii++)
		{
			int zf[9] = { 0 };
			int si = (ii % 3) * 3;
			for (int cnt=0;cnt < 3;si++,cnt++)
			{
				
				for (int sj = (ii / 3)*3,ct=0;ct<3;ct++, sj++)
				{

					if (board[si][sj] == '.')
						continue;
					else if (board[si][sj] > '9' || board[si][sj] < '1')
						return false;
					else if (zf[board[si][sj] - '0' - 1] != 0)
						return false;
					else
						zf[board[si][sj] - '0' - 1]++;
				}
			}
		}

		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	
	vector<vector<char>> input;

	vector<char> roll1 = { '.', '.', '.', '.', '5', '.', '.', '1', '.' };
	vector<char> roll2 = { '.', '4', '.', '3', '.', '.', '.', '.', '.' };
	vector<char> roll3 = { '.', '.', '.', '.', '.', '3', '.', '.', '1' };
	vector<char> roll4 = { '8', '.', '.', '.', '.', '.', '.', '2', '.' };
	vector<char> roll5 = { '.', '.', '2', '.', '7', '.', '.', '.', '.' };
	vector<char> roll6 = { '.', '1', '5', '.', '.', '.', '.', '.', '.' };
	vector<char> roll7 = { '.', '.', '.', '.', '.', '2', '.', '.', '.' };
	vector<char> roll8 = { '.', '2', '9', '.', '.', '.', '.', '.', '.' };
	vector<char> roll9 = { '.', '.', '4', '.', '.', '.', '.', '.', '.' };
	/*
	string 
	a = "........2";vector<char> roll1 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "......6..";vector<char> roll2 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "..14..8..";vector<char> roll3 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = ".........";vector<char> roll4 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = ".........";vector<char> roll5 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "....3....";vector<char> roll6 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "5.86.....";vector<char> roll7 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = ".9....4..";vector<char> roll8 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "....5....";vector<char> roll9 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };*/
	/*
	string
	a = ".87654321";vector<char> roll1 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "2........";vector<char> roll2 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "3........";vector<char> roll3 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "4........";vector<char> roll4 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "5........";vector<char> roll5 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "6........";vector<char> roll6 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "7........";vector<char> roll7 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "8........";vector<char> roll8 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };
	a = "9........";vector<char> roll9 = { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] };*/

	input.push_back(roll1);
	input.push_back(roll2);
	input.push_back(roll3);
	input.push_back(roll4);
	input.push_back(roll5);
	input.push_back(roll6);
	input.push_back(roll7);
	input.push_back(roll8);
	input.push_back(roll9);

	cout << s.isValidSudoku(input);
	return 0;
}