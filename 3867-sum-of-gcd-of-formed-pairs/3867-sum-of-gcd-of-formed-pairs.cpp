class Solution {
public:

    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> mxi(n);
        vector<int> prefixGcd(n);
        mxi[0]=nums[0];
        int maxi=0;
        for(int i=1; i<n; i++){
            mxi[i]=max(mxi[i-1],nums[i]);
        }

        for(int i=0; i<n; i++){
            prefixGcd[i]=gcd(nums[i],mxi[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<j){
            ans+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};