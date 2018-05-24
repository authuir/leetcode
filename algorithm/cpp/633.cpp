class Solution {
public:
    bool judgeSquareSum(int c) {
        int max_d = ceil(sqrt(double(c))) + 1;
        for (int i=0 ; i<max_d; i++)
        {
            double tmp = sqrt(double(c) - i*i);
            if (tmp - floor(tmp) < 0.00001)
            {
                return true;
            }
        }
        return false;
    }
};