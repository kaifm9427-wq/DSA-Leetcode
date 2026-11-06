class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp1={}
        for x in ransomNote:
            mp1[x]=mp1.get(x,0)+1
        
        mp2={}
        for x in magazine:
            mp2[x]=mp2.get(x,0)+1
        
        for(key1,value1) in mp1.items():
            if(key1 not in mp2 or value1>mp2[key1]):
                return False
        
        return True
        