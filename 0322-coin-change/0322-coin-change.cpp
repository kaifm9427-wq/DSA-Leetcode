class Solution {
public:
    int n;
    int dp[13][10001];
    int func(int ind,vector<int>& coins,int amount){
        if(ind>=n){
            return 1e9;
        }
        if(amount==0) return 0;
        if(amount<0) return 1e9;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=1+func(ind,coins,amount-coins[ind]);
        int notpick=func(ind+1,coins,amount);
        return dp[ind][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans= func(0,coins,amount);
        return ans>=1e9? -1:ans;
    }
};