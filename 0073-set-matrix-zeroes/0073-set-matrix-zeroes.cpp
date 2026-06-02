class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Your code goes here
        int n=matrix.size();
        int m=matrix[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        vector<vector<int>> point;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    point.push_back({i,j});
                }
            }
        }
        for(int i=0; i<point.size(); i++){
            int row=point[i][0];
            int col=point[i][1];

            for(int j=0; j<n; j++){
                matrix[j][col]=0;
            }
            for(int j=0; j<m; j++){
                matrix[row][j]=0;
            }
        }
        

    }
};