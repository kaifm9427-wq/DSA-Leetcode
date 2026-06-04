class Solution {
public:
    int n;
    vector<int> dp;

    int func(int i, vector<int>& nums){
        if(i == 0) return nums[0];

        if(dp[i] != INT_MIN) return dp[i];

        int extend = nums[i] + func(i - 1, nums);
        int startNew = nums[i];

        return dp[i] = max(startNew, extend);
    }

    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, INT_MIN);

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            ans = max(ans, func(i, nums));
        }

        return ans;
    }
};