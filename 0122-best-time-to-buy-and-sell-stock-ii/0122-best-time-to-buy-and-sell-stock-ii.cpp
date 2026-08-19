class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int pickmin=INT_MAX;
        int pickmax=INT_MIN;
        int sell=0;
        int sum=0;
        int i=0;
        while(i<n){
            if(nums[i]<pickmin){
                pickmin=nums[i];
            }
            if(nums[i]>pickmax && nums[i]!=pickmin){
                pickmax=nums[i];
            }
            if(pickmin!=INT_MAX && pickmax!=INT_MIN){
                sell=pickmax-pickmin;
                sum+=sell;
                pickmax=INT_MIN;
                pickmin=nums[i];
            }
            i++;
        }
        return sum;

    }
};