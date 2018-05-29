#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> tmp;
        vector<string> rtn;
        
        for (int i=0 ; i < S.size() ; i++)
        {
            if (S[i] >= 'a' && S[i] <= 'z')
                tmp.push_back(i);
            else if (S[i] >= 'A' && S[i] <= 'Z')
                tmp.push_back(i);
        }
        if (tmp.size() == 0)
        {
            rtn.push_back(S);
            return rtn;
        }
        int rtnx = pow(2, tmp.size());
        for (int i = 0; i<rtnx; i++)
        {
            string tmpString = S;
            for (int j = 0; j<tmp.size(); j++)
            {
                if ((i>>j) & 0x01)
                {
                    if (tmpString[tmp[j]] >= 'a' && tmpString[tmp[j]] <= 'z')
                        tmpString[tmp[j]] -= 32;
                }
                else
                {
                    if (tmpString[tmp[j]] >= 'A' && tmpString[tmp[j]] <= 'Z')
                        tmpString[tmp[j]] += 32;
                }
            }
            rtn.push_back(tmpString);
        }
        return rtn;
    }
};
 
int main(int argc, char const *argv[])
{
    Solution x;
    vector<string> rtn = x.letterCasePermutation("a1b2");
    for (auto g : rtn)
        cout << g << endl;
    cout << rtn.size();
    return 0;
}

