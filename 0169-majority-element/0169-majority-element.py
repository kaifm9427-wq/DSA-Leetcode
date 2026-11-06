class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        mp={}
        for x in nums:
            mp[x]=mp.get(x,0)+1
        
        n=len(nums)
        for key,value in mp.items():
            if(value>n/2):
                return key
        return -1