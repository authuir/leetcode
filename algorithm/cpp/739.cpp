class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> rtn;
        rtn.push_back(0);
        int largest = temperatures.back();
        for (int i = temperatures.size()-2; i >=0 ; i--)
        {
            if (temperatures[i] >= largest)
            {
                rtn.push_back(0);
                largest = temperatures[i];
            }
            else
            {
                rtn.push_back(0);
                int tmp_index = i+1;
                while (tmp_index < temperatures.size())
                {
                    if (temperatures[i] < temperatures[tmp_index])
                    {
                        rtn.pop_back();
                        rtn.push_back(tmp_index - i);
                        break;
                    }
                    tmp_index ++;
                }
            }
        }
        reverse(rtn.begin(), rtn.end());
        return rtn;
    }
};