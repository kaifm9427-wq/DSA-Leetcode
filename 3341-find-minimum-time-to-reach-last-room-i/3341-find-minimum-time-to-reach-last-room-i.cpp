class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    typedef pair<int,pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;

        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };

        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int t=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(t>result[x][y]) continue;
            for(int k=0; k<4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(isSafe(nx,ny)){
                    int nt=max(t,moveTime[nx][ny])+1;
                    if(nt<result[nx][ny]){
                        result[nx][ny]=nt;
                        pq.push({nt,{nx,ny}});
                    }
                }

            }
        }
        return result[n-1][m-1];
    }
};