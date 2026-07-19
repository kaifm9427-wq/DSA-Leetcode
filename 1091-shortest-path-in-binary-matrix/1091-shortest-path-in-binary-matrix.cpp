class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
        grid[0][0]=1;
        q.push({{0,0},1});
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = { 0,  1, 1, 1, 0,-1,-1, -1};
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            if(r==n-1 && c==m-1) return t;
            q.pop();
            for(int k=0; k<8; k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({{nr,nc},t+1});

                }
            }

        }
        return -1;
    }
};