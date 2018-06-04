#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) return true;
        unordered_set<int> unvisited;
        unordered_set<int> visited;
        unordered_set<int> visiting;
        for (int i=0; i<rooms.size(); i++)
            unvisited.insert(i);
        visiting.insert(0);
        
        while (true)
        {
            if (visiting.size() == 0)
                break;
            auto x = visiting.begin();
            for (auto iter : rooms[*x])
            {
                if (visited.find(iter) == visited.end())
                    visiting.insert(iter);
            }
            visited.insert(*x);
            unvisited.erase(*x);
            visiting.erase(x);
        }
        if (unvisited.size() != 0)
            return false;
        return true;
    }
};