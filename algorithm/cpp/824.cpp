#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string rtn;
        if (S.size() <= 0) return rtn;
        int count = 1;
        int header = 0;
        int ptr = header;
        for (; ptr < S.size(); ptr++)
        {
            if (S[ptr] == ' ')
            {
                if (S[header] == 'a' || S[header] == 'e' || S[header] == 'i' || S[header] == 'o' || S[header] == 'u' || 
                    S[header] == 'A' || S[header] == 'E' || S[header] == 'I' || S[header] == 'O' || S[header] == 'U' )
                {
                    for (int i=header; i<ptr; i++)
                    {
                        rtn = rtn.append(1,S[i]);
                    }
                }
                else
                {
                    for (int i=header+1; i<ptr; i++)
                    {
                        rtn = rtn.append(1,S[i]);
                    }
                    rtn = rtn.append(1,S[header]);
                }
                rtn = rtn.append("ma");
                rtn = rtn.append(count,'a');
                rtn = rtn.append(1,' ');
                count++;
                header = ptr + 1;
                //cout << rtn;
            }
        }
        if (S[header] == 'a' || S[header] == 'e' || S[header] == 'i' || S[header] == 'o' || S[header] == 'u' || 
            S[header] == 'A' || S[header] == 'E' || S[header] == 'I' || S[header] == 'O' || S[header] == 'U' )
        {
            for (int i=header; i<ptr; i++)
                rtn = rtn.append(1,S[i]);
        }
        else
        {
            for (int i=header+1; i<ptr; i++)
                rtn = rtn.append(1,S[i]);
            rtn = rtn.append(1,S[header]);
        }
        rtn = rtn.append("ma");
        rtn = rtn.append(count,'a');
        return rtn;
    }
};

int main()
{
    Solution x;
    cout << x.toGoatLatin("I speak Goat Latin");
    return 0;
}