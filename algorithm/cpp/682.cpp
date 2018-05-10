#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> history;
        int rtn = 0;
        for ( auto iter : ops)
        {
            if (iter == "C")
            {
                if (history.size() >= 1)
                {
                    int tmp = history.top();
                    history.pop();
                    rtn -= tmp;
                }
            }
            else if (iter == "D")
            {
                if (history.size() >= 1)
                {
                    int tmp = history.top();
                    rtn += tmp*2;
                    history.push(tmp*2);
                }
            }
            else if (iter == "+")
            {
                if (history.size() >= 2)
                {
                    int tmp1 = history.top();
                    history.pop();
                    int tmp2 = history.top();
                    history.push(tmp1);
                    rtn += (tmp1 + tmp2);
                    history.push(tmp1 + tmp2);
                }
            }
            else
            {
                int tmp = stoi(iter);
                rtn += tmp;
                history.push(tmp);
            }
        }
        return rtn;
    }
};

int main()
{
    return 0;
}