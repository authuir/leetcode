
class Solution {
public:
    vector<vector<int>> rtn;
    void search(vector<vector<int>>& graph, vector<int> next)
    {
        if (next.size() == 0) return;
        int x = next.back();
        if (x == graph.size()-1)
        {
            rtn.push_back(next);
            return;
        }
        for (auto iter : graph[x])
        {
            next.push_back(iter);
            search(graph, next);
            next.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        search(graph, vector<int>{0});
        return rtn;
    }
};