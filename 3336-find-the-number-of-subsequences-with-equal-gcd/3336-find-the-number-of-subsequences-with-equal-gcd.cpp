class Solution {
public:
    int MOD=1e9+7;
    int n;
    int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();

        int maxEl=*max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(maxEl + 1,vector<int>(maxEl + 1, 0)));

        //base case
        for(int first=0; first<=maxEl; first++){
            for(int second=0; second<=maxEl; second++){
                if(first!=0 && second!=0 && first==second){
                    
                    dp[n][first][second]=1;
                }else{
                    dp[n][first][second]=0;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int first=maxEl; first>=0; first--){
                for(int second=maxEl; second>=0; second--){
                    long long skip=dp[i+1][first][second];
                    long long take1=dp[i+1][gcd(first,nums[i])][second];
                    long long take2=dp[i+1][first][gcd(second,nums[i])];

                    dp[i][first][second]=(+skip+take1+take2)%MOD;
                }
            }
        }

        return dp[0][0][0];

    }
};