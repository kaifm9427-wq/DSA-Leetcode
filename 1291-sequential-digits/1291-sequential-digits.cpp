class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1; i<9; i++){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp>=low && temp<=high){
                ans.push_back(temp);
            }
            int dig=temp%10;
            if(dig+1<=9){
                q.push(temp*10 + (dig+1));
            }
            
        }
        return ans;
    }
};