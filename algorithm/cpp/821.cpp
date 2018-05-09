#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> marks;
        for (int i=0; i<S.size(); i++)
        {
            if (S[i] == C)
            {
                marks.push_back(i);
            }
        }
        int old = -10000;
        int i = 0;
        vector<int> rtn;
        for (auto iter : marks)
        {
            while (i<=iter)
            {
                if ((i-old) < (iter-i))
                {
                    rtn.push_back(i-old);
                }else{
                    rtn.push_back(iter-i);
                }
                i++;
                if (i==S.size())
                    return rtn;
            }
            old = iter;
        }
        while (i!=S.size())
        {
            rtn.push_back(i-old);
            i++;
        }
        return rtn;
    }
};

