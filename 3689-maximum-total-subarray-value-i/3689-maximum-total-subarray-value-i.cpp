class Solution {
public:
    // int miniVal(vector<int>& nums){
    //     int mini=INT_MAX;
    //     for(auto& it:nums){
    //         if(it<mini){
    //             mini=it;
    //         }
    //     }
    //     return mini;
    // }

    // int maxiVal(vector<int>& nums){
    //     int maxi=INT_MIN;
    //     for(auto& it:nums){
    //         if(it>maxi){
    //             maxi=it;
    //         }
    //     }
    //     return maxi;
    // }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        int maxi=0;
        int l=0,r=n-1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<k; i++){
            int min=nums[0];
            int max=nums[n-1];
            sum=sum+max-min;
        }
        return sum;
    }
};