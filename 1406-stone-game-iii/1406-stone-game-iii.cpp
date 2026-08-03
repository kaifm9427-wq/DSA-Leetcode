class Solution {
public:
    int n;
    int res = INT_MIN;
    vector<int> dp;

    int solve(int i, vector<int>& nums) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        res = nums[i] - solve(i + 1, nums);

        if (i + 1 < n) {
            res = max(res, nums[i] + nums[i + 1] - solve(i + 2, nums));
        }

        if (i + 2 < n) {
            res = max(res, nums[i] + nums[i + 1] + nums[i + 2] - solve(i + 3, nums));
        }

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1, INT_MIN);

        int ans = solve(0, stoneValue);

        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};