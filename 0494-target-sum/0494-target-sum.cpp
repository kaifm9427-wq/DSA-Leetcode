class Solution {
public:
    int n;
    int dp[21][2001];
    int func(int ind,vector<int>& nums,int target, int k){
        if(ind>=n){
            if(target==k) return 1;
            return 0;
        }
        if(dp[ind][target+1000]!=-1) return dp[ind][target+1000];
        int pickPlus=func(ind+1,nums,target-nums[ind],k);
        int pickMinus=func(ind+1,nums,target+nums[ind],k);
        return dp[ind][target+1000]=pickPlus+pickMinus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,nums,0,target);
    }
};