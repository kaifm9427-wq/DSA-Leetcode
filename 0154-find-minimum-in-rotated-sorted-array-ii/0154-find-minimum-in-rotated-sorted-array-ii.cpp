class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        for(int it:nums){
            if(it<mini){
                mini=it;
            }
        }
        return mini;
    }
};