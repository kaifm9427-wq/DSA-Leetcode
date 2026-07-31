class Solution {
public:
    int n;
    int dp[301][5001];
    int func(int ind,vector<int>& coins,int amount){
        if(ind>=n){
            if(amount==0) return 1;
            return 0;
        }
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=func(ind,coins,amount-coins[ind]);
        int notpick=func(ind+1,coins,amount);
        return dp[ind][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return func(0,coins,amount);
    }
};