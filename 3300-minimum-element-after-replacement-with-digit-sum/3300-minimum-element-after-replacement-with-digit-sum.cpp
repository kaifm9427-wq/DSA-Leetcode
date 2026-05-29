class Solution {
public:
    int sumDigit(int n){
        int sum=0;
        while(n){
            int dig=n%10;
            sum=sum+dig;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto& it:nums){
            int sum=sumDigit(it);
            if(sum<mini){
                mini=sum;
            }
        }
        return mini;
    }
};