class Solution {
public:
    int n;
    int dp[50001];

    int getNextInd(vector<vector<int>> &arr,int l, int target){
        int r=n-1;
        int res=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=target){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }

    int func(vector<vector<int>> &arr, int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int next=getNextInd(arr,i+1,arr[i][1]);
        int pick=arr[i][2]+func(arr,next);
        int notpick=func(arr,i+1);
        return dp[i]=max(pick,notpick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> arr(n,vector<int>(3,0));
        for(int i=0; i<n; i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        auto comp=[&](auto& vec1, auto& vec2){
            return vec1[0] < vec2[0];
        };
        sort(arr.begin(), arr.end(), comp);
        memset(dp,-1,sizeof(dp));
        return func(arr,0);

        
    }
};