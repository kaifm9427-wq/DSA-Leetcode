class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m), down(m);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<int> prefUp(m + 1), prefDown(m + 1);

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            vector<int> newUp(m), newDown(m);

            for (int i = 0; i < m; i++) {
                newUp[i] = prefDown[i];
                newDown[i] = (prefUp[m] - prefUp[i + 1] + MOD) % MOD;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};