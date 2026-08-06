class Solution {
public:
    int minCut(string s) {
        int n=s.size();

        //blue print code use
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            //lenght=1 substr
            t[i][i]=true;
        }
        
         //length>=2 substr
        for(int L=2; L<=n; L++){
            for(int i=0; i<n-L+1; i++){
                int j=i+L-1;
                if(L==2){ //L=2 length subtr
                    t[i][j]=(s[i]==s[j]);
                }else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
            }
        }
        

        //dp fill
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            if(t[0][i]==true){
                dp[i]=0;
            }else{
                dp[i]=INT_MAX;
                for(int k=0; k<i; k++){
                    if(t[k+1][i]==true && 1+dp[k]<dp[i]){
                        dp[i]=1+dp[k];
                    }
                }
            }
        }
        return dp[n-1];

    }
};