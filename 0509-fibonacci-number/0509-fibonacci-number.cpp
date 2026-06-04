class Solution {
public:
    int dp[31];
    int func(int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1)+func(n-2);
    }
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n);
    }
};