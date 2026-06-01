class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        int sum=0;
        for(auto& it:cost) sum+=it;
        if(n==2) return sum;
        sort(cost.begin(), cost.end());
        int i=n-3;
        while(i>=0){
            ans=ans+cost[i];
            i=i-3;
            
        }
        return sum-ans;
    }
};