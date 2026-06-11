class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        int maxi = 0;

        for (auto &it : adj[node]) {
            if (!vis[it]) {
                maxi = max(maxi, dfs(it, adj, vis));
            }
        }

        return 1 + maxi;
    }

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = m + 1;

        vector<vector<int>> adj(n + 1);
        vector<int> vis(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = dfs(1, adj, vis); 

        int edgesInPath = depth - 1;

        if (edgesInPath == 0) return 0;

        return power(2, edgesInPath - 1);
    }
};