class Solution {
public:
    int n;
    int dp[201][10001];
    bool func(int ind,vector<int>& nums,int k){
        if(ind>=n){
            if(k==0) return true;
            return false;
        }
        if(k<0) return false;
        if(k==0) return true;
        if(dp[ind][k] !=-1) return dp[ind][k];
        int pick=func(ind+1,nums,k-nums[ind]);
        int notpick=func(ind+1,nums,k);
        return dp[ind][k]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        int target=sum/2;
        memset(dp,-1,sizeof(dp));
        return func(0,nums,target);
    }
};