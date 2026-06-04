class Solution {
public:
    int n;
    int dp[1001];
    int func(int ind, vector<int>& cost){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int takeOne=cost[ind]+func(ind+1,cost);
        int takeTwo=cost[ind]+func(ind+2,cost);
        return dp[ind]=min(takeOne,takeTwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        int cost1=func(0,cost);
        int cost2=func(1,cost);
        return min(cost1,cost2);
        
    }
};