class Solution {
public:
    string customSortString(string S, string T) {
        string rtn = "";
        int T_count[26] = {0};
        for (auto iter : T)
        {
            T_count[iter - 'a']++;
        }
        for (auto iter : S)
        {
            while (T_count[iter-'a'] > 0)
            {
                T_count[iter-'a']--;
                rtn.push_back(iter);
            }
        }
        for (int i=0; i<26; i++)
        {
            while (T_count[i] > 0)
            {
                T_count[i]--;
                rtn.push_back(i+'a');
            }
        }
        return rtn;
    }
};