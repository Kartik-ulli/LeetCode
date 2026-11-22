class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nums=list(set(nums))
        nums=sorted(nums)
        left=0
        result=1
        if len(nums)==0:
            return 0;
        for i in range(1,len(nums)):
            if((nums[i-1]+1)==nums[i]):
                if result<i-left+1:
                    result=i-left+1
            else:
                left=i
        return result
        