#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int rtn = 0;

	void search(vector<int> arr, int pos)
	{
		if (arr.size() == 0)
			return;

		for (int i=0; i<arr.size(); i++)
		{
			if (arr[i] % pos == 0 || pos % arr[i] == 0)
			{
				if (arr.size() == 1)
				{
					rtn++;
					return;
				}
				vector<int> tmp = arr;
				tmp.erase(tmp.begin() + i);
				search(tmp, pos + 1);
			}
		}
	}

public:
	int countArrangement(int N) {
		rtn = 0;
		vector<int> arr;
		for (int i = 1; i <= N; i++)
			arr.push_back(i);

		search(arr,1);
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.countArrangement(2) << endl;
	cout << x.countArrangement(3) << endl;
	cout << x.countArrangement(8) << endl;
	cout << x.countArrangement(10) << endl;
	return 0;
}