class Solution {
public:
    int n;
    int dp[]
    int func(int ind,vector<int>& nums,int target, int k){
        if(ind>=n){
            if(target==k) return 1;
            return 0;
        }
        
        int pickPlus=func(ind+1,nums,target-nums[ind],k);
        int pickMinus=func(ind+1,nums,target+nums[ind],k);
        return pickPlus+pickMinus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        return func(0,nums,0,target);
    }
};