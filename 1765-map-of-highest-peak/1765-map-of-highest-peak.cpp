class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    q.push({{i,j},0});
                    dist[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    dist[nr][nc]=t+1;
                    vis[nr][nc]=1;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        return dist;
    }
};