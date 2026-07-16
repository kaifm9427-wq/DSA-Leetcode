class Solution {
public:
    int n,m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        for(int k=0; k<4; k++){
            dfs(i+dx[k],j+dy[k],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};