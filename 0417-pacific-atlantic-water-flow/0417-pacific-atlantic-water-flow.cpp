class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int n,m;
    void dfs(vector<vector<int>>& heights, int i, int j,vector<vector<int>>& visited, int prev){
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || heights[i][j]<prev) return;
        visited[i][j]=1;
        for(int k=0; k<4; k++){
            dfs(heights,i+dx[k], j+dy[k],visited,heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> pacificVisited(n,vector<int>(m,0));
        vector<vector<int>> atlanticVisited(n,vector<int>(m,0)); 

        // top and left--> pacific ocean

        for(int i=0; i<m; i++){
            dfs(heights,0,i,pacificVisited,INT_MIN);
            dfs(heights,n-1,i,atlanticVisited,INT_MIN);
        }

        for(int i=0; i<n; i++){
            dfs(heights,i,0,pacificVisited,INT_MIN);
            dfs(heights,i,m-1,atlanticVisited,INT_MIN);
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacificVisited[i][j]==1 && atlanticVisited[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};