#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double rtn = 0;
        for(int a = 0 ; a < points.size() - 2 ; a++)
            for(int b = a+1 ; b < points.size() - 1 ; b++)
                for(int c = b+1 ; c < points.size() ; c++)
                {
                    double tmp = areaByPoint(points[a], points[b], points[c]);
                    if (tmp > rtn)
                        rtn = tmp;
                }
        return rtn;
    }
    double lengthByPoint(vector<int>& a, vector<int>& b){
        double rtn;
        rtn = sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
        return rtn;
    }
    double areaByPoint(vector<int>& a, vector<int>& b, vector<int>& c){
        double s1 = lengthByPoint(a, b);
        double s2 = lengthByPoint(c, b);
        double s3 = lengthByPoint(a, c);
        double s = (s1+s2+s3) / 2.0 ;
        double tmp = s*(s-s1)*(s-s2)*(s-s3);
        if (tmp < 0) return 0;
        return sqrt(tmp);
    }
};

int main()
{
    Solution x;
    return 0;
}