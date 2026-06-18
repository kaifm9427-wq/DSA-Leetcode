class Solution {
private:
    void func(int idx, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(arr);
            return;
        }
        func(1+idx,nums,arr,ans);
        arr.push_back(nums[idx]);
        func(idx+1,nums,arr,ans);
        arr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<int> arr;
        vector<vector<int>> ans;
        func(0,nums,arr,ans);
        return ans;
    }
};