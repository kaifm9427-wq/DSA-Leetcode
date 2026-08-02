class Solution {
public:
    int dp[501][501];
    int solve(int i,vector<int>& piles,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=piles[i]+min(solve(i+2,piles,j), solve(i+1,piles,j-1));
        int take_j=piles[j]+min(solve(i+1,piles,j-1),solve(i,piles,j-2));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        memset(dp,-1,sizeof(dp));
        int res=solve(0,piles,n-1);
        if(res>sum/2) return true;
        return false;
    }
};