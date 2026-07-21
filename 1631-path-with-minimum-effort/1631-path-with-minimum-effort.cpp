class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int k=0; k<4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(isSafe(nx,ny)){
                    int absDiff=abs(heights[x][y]-heights[nx][ny]);
                    int maxDiff=max(diff,absDiff);
                    if(result[nx][ny]>maxDiff){
                        result[nx][ny]=maxDiff;
                        pq.push({maxDiff,{nx,ny}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};