class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        int maxiEl=0;

        for(int h=1; h<=n; h++){  
            int cnt=0;

            for(int j=0; j<n; j++){
                if(nums[j] >= h){
                    cnt++;
                }
            }

            if(cnt >= h){
                maxiEl=max(maxiEl,h);
            }
        }

        return maxiEl;
    }
};