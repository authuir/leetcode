#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int sizex = matrix.size();
        if (sizex == 0) return true;
        int sizey = matrix[0].size();
        if (sizex == 1 || sizey == 1) return true;
        int n_x_d = sizex - 1;
        int n_y_d = 0;
        int now = matrix[n_x_d][n_y_d];
        int stage = 0;
        int n_x = n_x_d;
        int n_y = n_y_d;
        
        while(true)
        {
            n_x = n_x + 1;
            n_y = n_y + 1;
            if ((n_x >= sizex || n_y >= sizey) && stage == 0)
            {
                n_x_d = n_x_d - 1;
                if (n_x_d == 0)
                    stage = 1;
                n_x = n_x_d;
                n_y = 0;
                now = matrix[n_x][n_y];
            }
            else if ((n_x >= sizex || n_y >= sizey) && stage == 1)
            {
                n_y_d = n_y_d + 1;
                if (n_y_d >= sizey)
                    return true;
                n_y = n_y_d;
                n_x = 0;
                now = matrix[n_x][n_y];
            }
            if (matrix[n_x][n_y] != now)
                return false;
        }
        return true;
    }
};