class Solution {
public:
    int bs(vector<int>&nums,int l, int r, int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(target>nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int peak=-1;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                peak=i;
                break;
            }
        }

        if(peak==-1) return bs(nums,0,n-1,target);
        int ans1=bs(nums,0,peak-1,target);
        if(ans1!=-1) return ans1;
        int ans2=bs(nums,peak,n-1,target);
        if(ans2!=-1) return ans2;
        return -1;
    }
};