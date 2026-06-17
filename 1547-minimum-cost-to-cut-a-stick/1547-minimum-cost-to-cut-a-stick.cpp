class Solution {
public:
    int dp[105][105];
    int func(int l,int r, vector<int>& cuts){
        if(r-l==1){
            return 0;
        }
        if (dp[l][r] != -1)
            return dp[l][r];
        
        int res=INT_MAX;
        for(int i=l+1; i<r; i++){
            int cost=cuts[r]-cuts[l]+func(l,i,cuts)+ func(i,r,cuts);
            res=min(res,cost);
        }
        return dp[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m=cuts.size();
        return func(0,m-1,cuts);
    }
};