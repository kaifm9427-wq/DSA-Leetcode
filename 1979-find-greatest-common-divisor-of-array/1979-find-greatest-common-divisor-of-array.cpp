class Solution {
public:

    int gcd(int a, int b){
        if(a%b==0) return b;
        return gcd(b,a%b);
    }

    int findGCD(vector<int>& nums) {
        int sm=INT_MAX;;
        int lg=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>lg){
                lg=nums[i];
            }
            if(nums[i]<sm){
                sm=nums[i];
            }
        }
        int ans=gcd(sm,lg);
        return ans;
    }
};