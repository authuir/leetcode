#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
private:
    string convert2morse(string& words)
    {
        const static vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string rtn;
        for (auto x : words)
        {
            rtn.append(table[x-'a']);
        }
        return rtn;
    }

    unordered_set<string> sx;

public:
    int uniqueMorseRepresentations(vector<string>& words) {
        for (auto x: words)
        {
            sx.insert(convert2morse(x));
        }
        return sx.size();
    }
};

int main()
{
    Solution x;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << x.uniqueMorseRepresentations(words);
    return 0;
}