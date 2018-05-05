#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    bool is_self_divided(int numb)
    {
        vector<int> tmp;
        int x = numb;
        while (x>0)
        {
            tmp.push_back(x%10);
            x = x/10;
        }
        for (auto iter : tmp)
        {
            if (iter == 0)
                return false;
            if (iter != 0 && numb%iter != 0)
                return false;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> rtn;
        for (int iter = left; iter <= right ; iter++)
        {
            if (is_self_divided(iter))
                rtn.push_back(iter);
        }
        return rtn;
    }
};

int main()
{
    Solution x;
    auto a = x.selfDividingNumbers(10,22);
    for (auto iter : a)
        cout << iter;
    return 0;
}
