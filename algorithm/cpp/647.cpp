#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        for (int i=0; i<s.size(); i++)
        {
            local_storage.push_back(vector<int>{});
        }
        search(s.size() - 1, s);
        int rtn = 0;
        for (int i=0; i<s.size(); i++)
        {
            rtn += local_storage[i].size();
        }
        return rtn;
    }
private:
    vector<vector<int>> local_storage;
    void search(int n, const string & s)
    {
        if (local_storage[n].size() > 0)
            return ;
        local_storage[n].push_back(1);
        if (n <= 0)
            return ;
        search(n-1, s);
        for (auto iter : local_storage[n-1])
        {
            if (iter == 1 && s[n] == s[n-1])
                local_storage[n].push_back(2);
            if (n - 1 - iter >= 0)
            {
                if (s[n] == s[n-1-iter])
                    local_storage[n].push_back(iter + 2);
            }
        }
    }
};

int main()
{
    Solution x;
    string str = "aaa";
    cout << x.countSubstrings(str);
    return 0;
}
