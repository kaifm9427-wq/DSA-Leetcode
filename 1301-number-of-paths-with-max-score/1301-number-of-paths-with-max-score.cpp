class Solution {
public:
    int dx[3]={0,-1,-1};
    int dy[3]={-1,-1,0};
    int n;
    int m;
    int mod=1e9+7;
    pair<int,int> dp[101][101];
    pair<int,int> func(int i,int j,vector<vector<int>>& board){
        if(i>=n || i<0 || j<0 || j>=m || board[i][j]==-1){
            return {-1,0};
        }
        if(i==0 && j==0){
            return {0,1};
        }
        if(dp[i][j].first!=-2){
            return dp[i][j];
        }
        int maxi=-1;
        long long ways=0;
        for(int k=0; k<3; k++){
            auto prev=func(i+dx[k],j+dy[k],board);
            if(prev.first==-1) continue;
            if(prev.first>maxi){
                maxi=prev.first;
                ways=prev.second;
            }else if(prev.first==maxi){
                ways=(ways+prev.second)%mod;
            }

        }
        if(maxi==-1){
            return dp[i][j]={-1,0};
        }
        int score=maxi+board[i][j];
        return dp[i][j]={score,(int)(ways%mod)};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X'){
                    grid[i][j]=-1;
                }
                else if(board[i][j]=='E'|| board[i][j]=='S'){
                    grid[i][j]=0;
                }else{
                    grid[i][j]=board[i][j]-'0';
                }   
            }
        }
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = {-2, -2};
            }
        }
        auto ans=func(n-1,m-1,grid);
        if(ans.first==-1){
            return {0,0};
        }
        return {ans.first,ans.second};

    }
};