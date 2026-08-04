class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max_el = *max_element(nums.begin(), nums.end());
        int min_el = *min_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int j = 0;

        for (int i = min_el; i <= max_el; i++) {
            if (j < nums.size() && nums[j] == i) {
                j++;
            } else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};