class Solution {
public:
    int func(vector<int>& nums, int mid){
        int cnt=1;
        int allocated=0;
        for(int i=0; i<nums.size(); i++){
            if(allocated+nums[i]<=mid){
                allocated+=nums[i];
            }else{
                allocated=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=func(nums,mid);
            if(cnt>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};