class Solution {
public:
    #define ll long long

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        ll N = 1LL * n * n;
        ll actualSum = 0;
        ll actualSqSum = 0;

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        ll expectedSum = N * (N + 1) / 2;                 
        ll expectedSqSum = N * (N + 1) * (2 * N + 1) / 6; 

        ll x = actualSum - expectedSum;
        ll y = (actualSqSum - expectedSqSum) / x;

        ll repeating = (x + y) / 2;
        ll missing = (y - x) / 2;

        return {(int)repeating, (int)missing}; 
    }
};