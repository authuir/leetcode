class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        rtn = 0
        for stone in S:
            for j in J:
                if stone == j:
                    rtn = rtn + 1
        return rtn