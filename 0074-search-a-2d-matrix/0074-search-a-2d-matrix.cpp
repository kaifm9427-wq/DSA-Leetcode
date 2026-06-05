class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            int val=mat[row][col];
            if(val==target){
                return true;
            }else if(val<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
};