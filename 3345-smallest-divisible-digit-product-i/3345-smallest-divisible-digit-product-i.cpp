class Solution {
public:
    bool check(int n,int t){
        vector<int> arr;
        while(n){
            int dig=n%10;
            arr.push_back(dig);
            n=n/10;
        }
        int ans=1;
        for(int i=0; i<arr.size(); i++){
            ans=ans*arr[i];
        }
        if(ans%t==0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<=n*t; i++){
            if(check(i,t)){
                return i;
            }
        }
        return -1;
    }
};