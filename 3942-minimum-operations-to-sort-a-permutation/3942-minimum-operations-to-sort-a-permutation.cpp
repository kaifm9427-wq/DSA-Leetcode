class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
            
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        bool is_forward = true;
        for (int j = 0; j < n; ++j) {
            if (nums[(idx + j) % n] != j) {
                is_forward = false;
                break;
            }
        }
                
        if (is_forward) {
            if (idx == 0) {
                return 0;
            }
            return std::min(idx, n - idx + 2);
        }
            
        bool is_backward = true;
        for (int j = 0; j < n; ++j) {
            int expected = (n - j) % n;
            if (nums[(idx + j) % n] != expected) {
                is_backward = false;
                break;
            }
        }
                
        if (is_backward) {
            return std::min(n - idx, idx + 2);
        }
            
        return -1;
    }
};