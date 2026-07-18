class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int cntFresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int cnt=0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int k=0; k<4; k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    cnt++;
                }
            }
        }
        if(cnt==cntFresh) return tm;
        return -1;

    }
};