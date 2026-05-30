class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        for(int x:nums){
            if(ans.size()<k || ans[ans.size()-k]!=x){
                ans.push_back(x);
            }
        }
        return ans;
    }
    
};