class Solution {
public:
    int dp[101];
    int func(int i, string s, int n){
        if(i>=n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int pickone=func(i+1,s,n);
        int picktwo=0;
        if(i+1<n){
            if(s[i]=='1' ||(s[i]=='2' && s[i+1]<='6')){
                picktwo=func(i+2,s,n);
            }
        }
        return dp[i]=pickone+picktwo;
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return func(0,s,n);
    }
};