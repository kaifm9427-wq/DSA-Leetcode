class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-1;
        int cntMax1=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>max1){
                max1=nums[i];
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]==max1) cntMax1++;
        }
        if(cntMax1>1) return (max1-1)*(max1-1);
        int max2=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>max2 && nums[i]<max1){
                max2=nums[i];
            }
        }
        return (max1-1)*(max2-1);
    }
};