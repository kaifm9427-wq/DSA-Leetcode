class Solution {
public:
    int n;
    int dp[100001][2][3];
    
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,0,sizeof(dp));
       

        for(int i=0; i<=n; i++){
            for(int buy=0; buy<2; buy++){
                dp[i][buy][0]=0;
            }
        }

        for(int buy=0; buy<2; buy++){
            for(int cap=0; cap<3; cap++){
                dp[n][buy][cap]=0;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<3; cap++){
                    int pick=0;
                    int notpick=0;
                    if(buy==1){
                        pick=-prices[i]+dp[i+1][0][cap];
                        notpick=dp[i+1][1][cap];
                    }else{
                        pick=prices[i]+dp[i+1][1][cap-1];
                        notpick=dp[i+1][0][cap];
                    }
                    dp[i][buy][cap]=max(pick,notpick);
                }
                
            }
        }
        return dp[0][1][2];
    }
};