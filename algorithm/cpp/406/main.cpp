#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<pair<int, int>> rtn;
	bool isnext(vector<pair<int, int>>::iterator iter)
	{
		int cnt = 0;
		for (auto ix = rtn.begin(); ix != rtn.end(); ix++)
		{
			if ((*ix).first >= (*iter).first)
				cnt++;
		}
		if (cnt == (*iter).second)
			return true;
		return false;
	}

public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		if (people.size() == 0) return rtn;
		if (people.size() == 1) return people;

		pair<int, int> head = { -1, -1 };
		for (auto iter : people)
		{
			if (iter.second == 0)
			{
				if (head.first > iter.first)
				{
					head = iter;
				}
				else if (head.first == iter.first)
				{
					if (head.second > iter.second)
						head = iter;
				}
				if (head.first == -1)
					head = iter;
			}
		}
		rtn.push_back(head);
		pair<int, int> del = { -1,-1 };
		while (true)
		{
			if (people.empty())
				break;
			else
			{
				pair<int, int> tmp = { 10000000,10000000 };
				for (vector<pair<int,int>>::iterator iter = people.begin(); iter != people.end(); iter++)
				{
					if ((*iter) == head)
					{
						iter = people.erase(iter);
						if (iter == people.end())
							break;
					}
					if ((*iter) == del)
					{
						iter = people.erase(iter);
						if (iter == people.end())
							break;
					}
					if (isnext(iter))
					{
						if (tmp.first > (*iter).first)
						{
							tmp = (*iter);
						}
						else if (tmp.first == (*iter).first)
						{
							if (tmp.second > (*iter).second)
								tmp = (*iter);
						}
					}
				}
				if (tmp != pair<int, int>{ 10000000, 10000000 })
				{

					del = tmp;
					rtn.push_back(tmp);
				}
			}

		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.reconstructQueue(vector<pair<int, int>>{
		{ {6, 0}, { 5,0 }, { 4,0 }, { 3,2 }, { 2,2 }, { 1,4 }}
	});
	return 0;
}