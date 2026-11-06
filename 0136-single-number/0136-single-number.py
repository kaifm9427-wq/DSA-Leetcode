class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        mp={}
        for x in nums:
            mp[x]=mp.get(x,0)+1
        
        ans=0
        for key,value in mp.items():
            if(value==1):
                ans=key
                break
        
        return ans