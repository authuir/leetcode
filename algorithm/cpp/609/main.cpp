#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
	map<string, vector<string>> storage;

	void handleFile(string path, string str)
	{
		string filename = "";
		string content = "";
		int stat = 0;  //0:name, 1:content
		for (auto iter = str.begin(); iter != str.end(); iter++)
		{
			if (stat == 0)
			{
				if (*iter == '(')
				{
					stat = 1;
				}
				else
				{
					filename.push_back(*iter);
				}
			}
			else
			{
				if (*iter == ')')
				{
					string tmp = path + "/" + filename;
					storage[content].push_back(tmp);

					filename = "";
					content = "";
					if ((iter + 1) == str.end())
					{
						break;
					}
					if (*(iter + 1) == ' ')
						iter++;
					stat = 0;
				}
				else
				{
					content.push_back(*iter);
				}
			}
		}
	}

	void resolveStr(string str)
	{
		string path = "";
		bool flag = true;
		for (auto iter = str.begin(); iter != str.end(); iter++)
		{
			if (flag)
			{
				if (*iter != ' ')
				{
					path.push_back(*iter);
				}
				else
					flag = false;
			}
			else
			{
				str.assign(iter, str.end());
				handleFile(path, str);
				break;
			}
		}
	}

public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> rtn;

		for (auto iter = paths.begin(); iter != paths.end(); iter++)
		{
			resolveStr(*iter);
		}

		for (auto iter = storage.begin(); iter != storage.end(); iter++)
		{
			if ((*iter).second.size() > 1)
			{
				vector<string> tmp;
				for (auto ii = (*iter).second.begin(); ii != (*iter).second.end(); ii++)
				{
					tmp.push_back(*ii);
				}
				rtn.push_back(tmp);
			}
		}

		return rtn;
	}
};

int main()
{
	Solution x;
	vector<string> input = { "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)" };
	x.findDuplicate(input);
	return 0;
}