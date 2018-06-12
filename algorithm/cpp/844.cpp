class Solution {
public:
    string handle_sharp(string S) {
        string rtn;
        for (auto iter : S) {
            if (iter == '#' && rtn.size() > 0)
                rtn.pop_back();
            else if (iter != '#')
                rtn.push_back(iter);
        }
        return rtn;
    }
    bool backspaceCompare(string S, string T) {
        string st = handle_sharp(S);
        string tt = handle_sharp(T);
        if (st == tt)
            return true;
        return false;
    }
};
