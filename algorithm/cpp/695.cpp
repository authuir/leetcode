#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

namespace std
{
    template<> struct hash<std::pair<int, int>>
    {
        size_t operator () (std::pair<int, int> const& p) const
        {
            return (std::hash<int>()(p.first)%1989499 + std::hash<int>()(p.second)%16546494);
        }
    };
}

class Solution {
public:
    vector<unordered_set<pair<int, int>>> islands;
    int isExsit(pair<int, int> origin)
    {

        for (int i=0; i< islands.size(); i++ )
        {
            if (islands[i].find(origin) != islands[i].end()  )
            {
                return i;
            }
        }
        return -1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int x_range = grid.size();
        if (x_range == 0)
            return 0;
        int y_range = grid[0].size();
        if (y_range == 0)
            return 0;
        
        for (int i=0; i<x_range; i++)
            for (int j=0; j<y_range; j++)
            {
                if (grid[i][j] == 1)
                {
                    auto origin = make_pair(i, j);
                    pair<int, int> x_1 = origin;
                    pair<int, int> y_1 = origin;
                    x_1.first -= 1;
                    y_1.second -= 1;

                    int x_result = isExsit(x_1);
                    int y_result = isExsit(y_1);

                    if (x_result != -1 && y_result != -1 && y_result != x_result)
                    {
                        for (auto iter = islands[y_result].begin(); iter !=islands[y_result].end(); iter++)
                        {
                            islands[x_result].insert(*iter);
                        }
                        islands[y_result].clear();
                        islands[x_result].insert(origin);
                    }
                    else if (x_result != -1)
                    {
                        islands[x_result].insert(origin);
                    }
                    else if (y_result != -1)
                    {
                        islands[y_result].insert(origin);
                    }
                    else
                    {
                        unordered_set<pair<int, int>> tmp;
                        tmp.insert(origin);
                        islands.push_back(tmp);
                    }
                }
            }
        
        int rtn = 0;
        for (auto iter : islands)
        {
        //     cout << "----" << endl;
            int size = iter.size();
            if (size > rtn)
                rtn = size;
            // for (auto i : iter)
            // {
            //     cout << i.first << i.second << endl;
            // }
        }
        return rtn;
    }
};


int main(int argc, char const *argv[])
{
    Solution x;
    vector<vector<int>> input;
    input.push_back(vector<int>{1,1,0,0,0});
    input.push_back(vector<int>{1,1,0,0,0});
    input.push_back(vector<int>{0,0,0,1,1});
    input.push_back(vector<int>{0,0,0,1,1});
    cout << x.maxAreaOfIsland(input);
    return 0;
}
