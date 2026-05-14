class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;

    int func(int i, int j, vector<vector<int>>& grid, int k){
        if(i>=n || j>=m) return -1e9;
        int cost = (grid[i][j] == 0 ? 0 : 1);
        if(k < cost) return -1e9;
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int right = func(i, j+1, grid, k - cost);
        int down  = func(i+1, j, grid, k - cost);
        int best = max(right, down);
        if(best == -1e9) return dp[i][j][k] = -1e9;
        return dp[i][j][k] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = func(0,0,grid,k);

        return ans < 0 ? -1 : ans;
    }
};