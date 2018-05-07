#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
unordered_map<string, int> rtn;
    void adder(string str, int times)
    {
        auto rst = rtn.find(str);
        if (rst != rtn.end())
        {
            rtn[str] += times;
        }
        else
        {
            rtn.insert(std::make_pair(str, times));
        }
    }
    void handle(string input,int times)
    {
        vector<int> ppos;
        for (int i = 0 ; i<input.size() ; i ++)
        {
            if (input[i] == '.')
                ppos.push_back(i);
        }
        if (ppos.size() == 1)
        {
            adder(input.substr(ppos[0]+1, input.size()), times);
            adder(input, times);
        }
        else if (ppos.size() == 2)
        {
            adder(input.substr(ppos[0]+1, input.size()), times);
            adder(input.substr(ppos[1]+1, input.size()), times);
            adder(input, times);
        }
    }

public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (auto iter : cpdomains)
        {
            size_t space_location = iter.find(' ');
            if (space_location!=std::string::npos)
            {
                int times = stoi(iter,&space_location,0);

                handle(iter.substr(space_location+1), times);
            }
            
        }
        vector <string> result;
        for (auto iter : rtn)
        {
            string tmp = to_string(iter.second)+" "+iter.first;
            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
    Solution x;
    vector<string> input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    auto res = x.subdomainVisits(input);
    for (auto iter : res)
        cout << iter << endl;
    return 0;
}
