class Solution {
public:
    int dp[100001][2][3];
    int mod = 1e9 + 7;

    int func(int A, int L, int n){
        if(A > 1 || L > 2) return 0;

        if(n == 0){
            return 1;
        }

        if(dp[n][A][L] != -1) return dp[n][A][L];

        int absent = func(A + 1, 0, n - 1);
        int late = func(A, L + 1, n - 1);
        int present = func(A, 0, n - 1);

        return dp[n][A][L] = (1LL * absent + late + present) % mod; 
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return func(0, 0, n);
    }
};