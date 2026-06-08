class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int> left;
        vector<int> right;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]>pivot){
                right.push_back(nums[i]);
            }
        }
        vector<int> ans(left.begin(), left.end());
        for(int i=0; i<n; i++){
            if(nums[i]==pivot){
                ans.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(),right.begin(), right.end());
        return ans;
    }
};