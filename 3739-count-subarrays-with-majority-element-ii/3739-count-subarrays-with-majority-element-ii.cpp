class Fenwick {
public:
    vector<long long> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        Fenwick ft(2 * n + 5);

        int shift = n + 2;
        int pref = 0;
        long long ans = 0;

        ft.update(shift, 1);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += ft.query(pref + shift - 1);

            ft.update(pref + shift, 1);
        }

        return ans;
    }
};