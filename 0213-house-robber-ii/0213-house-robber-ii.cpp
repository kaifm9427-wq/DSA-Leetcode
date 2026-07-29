class Solution {
public:
    int dp[101];
    int func(int idx,vector<int>& nums){
        int n=nums.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+func(idx+2,nums);
        int notPick=func(idx+1,nums);
        return dp[idx]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1;
        for(int i=0; i<n-1; i++) arr1.push_back(nums[i]);
        vector<int> arr2;
        for(int i=1; i<n; i++) arr2.push_back(nums[i]);
        memset(dp,-1,sizeof(dp));
        int ans1=func(0,arr1);
        memset(dp,-1,sizeof(dp));
        int ans2=func(0,arr2);
        return max(ans1,ans2);
    }
};