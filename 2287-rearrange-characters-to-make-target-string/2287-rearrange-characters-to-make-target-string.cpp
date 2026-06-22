class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto& it:s){
            mp[it]++;
        }
        unordered_map<char,int> mp1;
        for(auto& it:target){
            mp1[it]++;
        }
        int ans=INT_MAX;
        for(auto& it:mp1){
            ans=min(ans,mp[it.first]/it.second);
        }
        return ans;
    }
};