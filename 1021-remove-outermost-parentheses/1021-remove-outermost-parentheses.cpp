class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        int i=0;
        int prev=i;
        vector<pair<int,int>> index;
        while(i<n){
            if(s[i]=='('){
                open++;
            }else if(s[i]==')'){
                close++;
            }
            if(open!=0 && close!=0 && open==close){
                index.push_back({prev,i});
                prev=i+1;
                open=0;
                close=0;
            }
            i++;
        }

        string ans="";
        int m=index.size();
        for(int i=0; i<m; i++){
            for(int j=index[i].first+1; j<index[i].second; j++){
                ans=ans+s[j];
            }
        }
        return ans;
    }
};