class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> order;
        string tmp = ""; 
        for (auto iter : paragraph)
        {
            if ( (iter >= 'a' && iter <= 'z') || (iter >= 'A' && iter <= 'Z') )
            {
                if (iter >= 'A' && iter <= 'Z')
                {
                    iter = iter + 32;
                }
                tmp.push_back(iter);
            }
            else if (tmp.size() > 0)
            {
                auto got = order.find(tmp);
                if ( got == order.end() )
                {
                    if (find(banned.begin(), banned.end(), tmp) == banned.end())
                        order.insert({tmp,1});
                    tmp = "";
                }
                else
                {
                    got->second++;
                }
            }
        }
        string rtn = "";
        int count  = 0;
        for (auto iter : order)
        {
            if (iter.second > count)
            {
                rtn = iter.first;
                count = iter.second;
            }
                
        }
        return rtn;
    }
};
