class Solution {
public:
    bool hasAlternatingBits(int n) {
        int xbit = n & 0x01;
        
        while (n > 0)
        {
            n = n>>1;
            int tmp_xbit = n & 0x01;
            if (tmp_xbit==xbit)
                return false;
            xbit = tmp_xbit;
        }
        
        return true;
    }
};

int main()
{
    Solution x;
    x.hasAlternatingBits(5);
    return 0;
}