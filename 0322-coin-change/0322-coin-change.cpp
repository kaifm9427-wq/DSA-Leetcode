class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=amount; j++){
                int pick=1e9;
                if(j>=coins[i]){
                    pick=1+dp[i][j-coins[i]];
                }
                int notpick=dp[i+1][j];
                dp[i][j]=min(pick,notpick);
            }
        }
        return dp[0][amount]>=1e9? -1: dp[0][amount];
    }
};