class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        self.index = 0

        if len(nums) <= 1:
            return True
        while True:
            pos = self.index
            if pos+nums[pos]+1 >= len(nums):
                return True
            
            max_dis = -1
            max_dis_ptr = -1

            for i in range(nums[pos]):
                pox_here = i+1+pos
                if nums[pox_here]+pox_here > max_dis:
                    max_dis = nums[pox_here]+pox_here
                    max_dis_ptr = pox_here
            if max_dis+1 >= len(nums):
                return True
            if max_dis == -1:
                return False

            self.index = max_dis_ptr