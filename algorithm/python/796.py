class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        lens = len(A)
        lens_b = len(B)
        if (lens != lens_b):
            return False
        
        if (lens == 0 and lens_b == 0):
            return True

        for i in range(lens):
            flag = True
            for j in range(lens):
                if (A[(i+j)%lens] != B[j]):
                    flag = False
                    break
            if flag:
                return True

        return False
                    