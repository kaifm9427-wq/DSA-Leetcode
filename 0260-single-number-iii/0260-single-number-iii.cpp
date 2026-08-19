class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        for(int i=0; i<n; i++){
            result=result^nums[i];
        }
        int mask=(result)&(-result);
        int grpA=0;
        int grpB=0;
        for(int i=0; i<n; i++){
            if((mask & nums[i])!=0){
                grpA^=nums[i];
            }else{
                grpB^=nums[i];
            }
        }
        return {grpA, grpB};
    }
};