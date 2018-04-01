class Solution {
public:
    bool isSubsequence(string s, string t) {
        return x(s,t,0,0);
    }
    bool x(string& s, string& t, int si, int ti)
    {
        if (si >= s.size()) return true;
        while (t.size() > ti)
        {
            if (s[si] == t[ti])
            {
                if ((s.size() - si) == 1)
                    return true;
                return x(s, t, si+1, ti+1 );
            }
            else
            {
                ti++;
            }
        }
        return false;
    }
};