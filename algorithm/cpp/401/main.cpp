#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<string> searchH(int num)
	{
		switch (num)
		{
		case 0: return vector<string>{"0"};break;
		case 1: return vector<string>{"1", "2", "4", "8"};break;
		case 2: return vector<string>{"3", "5", "9", "6", "10"};break;
		case 3: return vector<string>{"7", "11"};break;
		default: return vector<string>{};break;
		}
	}

	vector<string> searchM(int num)
	{
		switch (num)
		{
		case 0: return vector<string>{"00"};break;
		case 1: return vector<string>{"01", "02", "04", "08", "16", "32"};break;
		case 2: return vector<string>{"03","05","09","17","33","06","10","18","34","12","20","36","24","40","48"};break;
		case 3: return vector<string>{"07","11","19","35","13","21","37","25","41","49","14","22","38","26","42","50","28","44","52","56"};break;
		case 4: return vector<string>{"15","23","39","27","43","51","29","45","53","57","30","46","54","58"};break;
		case 5: return vector<string>{"31","47","55","59"};break;
		default: return vector<string>{};break;
		}
	}

public:
	vector<string> readBinaryWatch(int num) {
		if (num < 0) return  vector<string>{"0:00"};
		if (num == 0) return vector<string>{"0:00"};
		vector<string> rtn;
		for (int i = 0; i <= num; i++)
		{
			vector<string> H = searchH(i);
			vector<string> M = searchM(num - i);
			for (auto iter1 = H.begin(); iter1 != H.end(); iter1++)
			{
				for (auto iter2 = M.begin(); iter2 != M.end(); iter2++)
				{
					rtn.push_back((*iter1)+":"+(*iter2));
				}
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;

	return 0;
}