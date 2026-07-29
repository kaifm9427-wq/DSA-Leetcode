class Solution {
public:
    int n;
    int dp[20001];
    int func(int idx,vector<int>& nums){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int notpick=func(idx+1,nums);
        int pick=nums[idx]+func(idx+2,nums);
        return dp[idx]=max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxEl=*max_element(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        vector<int> arr(maxEl+1);
        n=nums.size();
        for(int i=0; i<n; i++){
            arr[nums[i]]+=nums[i];
        }
        n=arr.size();
        return func(0,arr);

    }
};