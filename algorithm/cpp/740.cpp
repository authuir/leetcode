#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if ( nums.size() == 0 ) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        map<int, int> input ;
        int tmp = nums[0];
        int cnt = 0;
        for (int i=0; i<nums.size()+1; i++) {
            if (i == nums.size() || nums[i] != tmp) {
                input[tmp] = cnt;
                cnt = 1;
                tmp = nums[i];
            } else {
                cnt++;
            }
        }
        handle(input, 0);
        return rtn;
    }
    
    map<map<int, int>, int> storage;
    int rtn = 0;
    
    void handle(map<int, int>& input, int score) {
        // for (auto iter : input)
        // {
        //     cout << iter.first << "->" << iter.second << endl;
        // }
        // cout << endl;
        if (input.size() == 0)
        {
            if (score > rtn)
                rtn = score;
            return ;
        }

        auto x = storage.find(input);
        if (x != storage.end()) {
            if (score <= x->second)
                return;
            else
                x->second = score;
        } else {
            storage[input] = score;
        }

        for (auto iter : input) {
            map<int, int> cp = input;
            auto rst1 = cp.find(iter.first+1);
            auto rst2 = cp.find(iter.first-1);
            int newscore = score + iter.first*iter.second;
            if (rst1 != cp.end())
                cp.erase(rst1);
            if (rst2 != cp.end())
                cp.erase(rst2);
            cp.erase(cp.find(iter.first));
            handle(cp, newscore);
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution x;
    vector<int> input{12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93};
    x.deleteAndEarn(input);
    return 0;
}
