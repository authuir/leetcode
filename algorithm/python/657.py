class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        u_d = 0
        l_r = 0
        for i in moves:
            if i == 'U':
                u_d = u_d + 1
            elif i == 'D':
                u_d = u_d - 1
            elif i == 'L':
                l_r = l_r + 1
            elif i == 'R':
                l_r = l_r - 1
        if u_d == 0 and l_r == 0:
            return True
        else:
            return False