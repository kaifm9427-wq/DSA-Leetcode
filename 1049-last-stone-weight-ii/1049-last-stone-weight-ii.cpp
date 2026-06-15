class Solution {
public:
    int n;
    int dp[31][3001];
    int func(int idx, int sum1, int total, vector<int>& stones) {
        if (idx == n) {
            int sum2 = total - sum1;
            return abs(sum1 - sum2);
        }
        if(dp[idx][sum1]!=-1) return dp[idx][sum1];
        int pick = func(idx + 1, sum1 + stones[idx], total, stones);
        int notPick = func(idx + 1, sum1, total, stones);

        return dp[idx][sum1]=min(pick, notPick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        int total = 0;
        memset(dp,-1,sizeof(dp));
        for (int x : stones) total += x;

        return func(0, 0, total, stones);
    }
};