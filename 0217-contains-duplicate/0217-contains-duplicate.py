class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        mp={}
        for x in nums:
            mp[x]=mp.get(x,0)+1
        
        for key,values in mp.items():
            if(values>1):
                return True
        
        return False