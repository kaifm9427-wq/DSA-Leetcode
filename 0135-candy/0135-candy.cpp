class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> leftCandy(n,1);
        vector<int> rightCandy(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                leftCandy[i]=leftCandy[i-1]+1;
            }
        }
        
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                rightCandy[i]=rightCandy[i+1]+1;
            }
        }

        int sum=0;
        
        for(int i=0; i<n; i++){
            sum=sum+max(leftCandy[i],rightCandy[i]);
        }
        return sum;

    }
};