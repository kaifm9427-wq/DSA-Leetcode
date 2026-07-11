class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<int>& vis,vector<int> &temp){
        vis[src]=1;
        temp.push_back(src);
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis,temp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i,adj,vis,temp);

                int size=temp.size();
                bool flag=true;
                for(auto node: temp){
                    if(adj[node].size()!=size-1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cnt++;
                }

            }
        }
        return cnt;
    }
};