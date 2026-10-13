class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n=arr.size();

        sort(arr.begin(),arr.end(),[](int a,int b){
            return abs(a)>abs(b);
        });

        long long maxsum=0;
        long long minsum=0;

        int mid=n/2;

        for(int i=0; i<=mid && n%2!=0; i++){
            maxsum += 1LL*arr[i]*arr[i];
        }

        if(n%2==0){
            for(int i=0; i<mid; i++){
                maxsum += 1LL*arr[i]*arr[i];
            }

            for(int i=mid; i<n; i++){
                minsum += 1LL*arr[i]*arr[i];
            }
        }
        else{
            for(int i=mid+1; i<n; i++){
                minsum += 1LL*arr[i]*arr[i];
            }
        }

        return maxsum-minsum;
    }
};