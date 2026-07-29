class Solution {
public:
    int dp[100001];
    int func(int idx, vector<int>& money){
        int n = money.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = money[idx] + func(idx + 2, money);
        int notPick = func(idx + 1, money);
        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& money) {
        memset(dp, -1, sizeof(dp));
        return func(0, money);
    }
};