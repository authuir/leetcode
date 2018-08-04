#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10002, 0);
        for (auto iter : nums) {
            arr[iter]++;
        }
        for (int i=2; i<10002; i++) {
            arr[i] = ((arr[i-2]+arr[i]*i) > arr[i-1]) ? (arr[i-2]+arr[i]*i) : arr[i-1];
        }
        return arr[10001];
    }
};
