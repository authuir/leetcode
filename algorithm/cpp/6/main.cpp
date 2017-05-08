#include <iostream>
#include <string>
using namespace std;
#define MAX 128
class Solution {
public:
	string convert(string s, int numRows) {
		string rtn;
		if (s.length() <= numRows || numRows < 2)
			return s;

		bool mod_long = true;
		bool arr_down = true;
		int row = 0;

		char * multi = new char[numRows * MAX];
		char * tmp = multi;
		int * rowcnt = new int[numRows];
		memset((void *)rowcnt, 0, sizeof(int)*numRows);
		memset((void *)multi, '\0', sizeof(char)*numRows * MAX);




		for (int i = 0;i < s.length();i++)
		{

			if (row == (numRows - 1))
				arr_down = false;
			else if (row == 0)
				arr_down = true;


			*(multi + row * MAX + rowcnt[row]) = s[i];
			rowcnt[row]++;
			arr_down ? row++ : row--;
		}
		for (int i = 0;i < numRows;i++)
		{
			int j = 0;
			while (*(multi + i * MAX + j) != '\0')
			{
				rtn.push_back(*(multi + i * MAX + j));
				j++;
			}
		}
		delete multi;
		delete rowcnt;
		return rtn;
	}
};

int main()
{
	Solution s;
	cout << s.convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.",
		2);
	cout << s.convert("AB", 1);
}