class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        
        int y_max = grid.size();
        int x_max = grid[0].size();
        
        vector<int> top_bottom(x_max);
        vector<int> left_right(y_max);
        
        for (int i = 0; i < x_max ; i++)
            top_bottom[i] = 0;
        for (int i = 0; i < y_max ; i++)
            left_right[i] = 0;
        
        
        for (int i = 0; i < x_max ; i++)
        {
            for (int j = 0; j < y_max ; j++)
            {
                if (grid[j][i] > top_bottom[i]) 
                    top_bottom[i] = grid[j][i];
                if (grid[j][i] > left_right[j]) 
                    left_right[j] = grid[j][i];
            }
        }
        
        int rtn = 0;
        
        for (int i = 0; i < x_max ; i++)
        {
            for (int j = 0; j < y_max ; j++)
            {
                if (grid[j][i] < top_bottom[i] && grid[j][i] < left_right[j]) 
                {
                    rtn += min(top_bottom[i], left_right[j]) - grid[j][i];
                }
            }
        }
        return rtn;
    }
};