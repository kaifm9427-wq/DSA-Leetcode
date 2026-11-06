class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp1={}
        for x in s:
            mp1[x]=mp1.get(x,0)+1
        
        mp2={}
        for x in t:
            mp2[x]=mp2.get(x,0)+1
        
        mp1=dict(sorted(mp1.items()))
        mp2=dict(sorted(mp2.items()))

        if len(mp1) != len(mp2):
            return False

        for(key1,value1), (key2,value2) in zip(mp1.items(), mp2.items()):
            if key1 != key2 or value1 != value2:
                return False
        
        return True