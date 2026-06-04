class Solution {
public:
    int dp[46];
    int func(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int takeOne=func(n-1);
        int takeTwo=func(n-2);
        return dp[n]=takeOne+takeTwo;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n);

    }
};