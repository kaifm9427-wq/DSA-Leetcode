class Solution {
public:
    int n;
    int dp[1001];
    int func(int i,vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pickone=nums[i]+func(i+1,nums);
        int picktwo=nums[i]+func(i+2,nums);
        return dp[i]=min(pickone,picktwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        int ans1=func(0,cost);
        memset(dp,-1,sizeof(dp));
        int ans2=func(1,cost);
        return min(ans1,ans2);
    }
};