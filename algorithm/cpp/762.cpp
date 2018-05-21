class Solution {
public:
    int countForSetBit(int x)
    {
        int rtn = 0;
        while (x > 0)
        {
            if (x & 0x01) 
                rtn++;
            x = x >> 1;
        }
        return rtn;
    }
    int countPrimeSetBits(int L, int R) {
        static int arr[21] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
        int rtn = 0;
        for (int i = L; i<=R; i++)
        {
            rtn += arr[countForSetBit(i)];
            //cout << i << " " << countForSetBit(i) << endl;
        }
        return rtn;
    }
};