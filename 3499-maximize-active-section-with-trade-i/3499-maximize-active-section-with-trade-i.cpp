class Solution {
public:
    
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int activeCnt=count(s.begin(), s.end(),'1');
        vector<int> zero;
        int i=0; 
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0') i++;
                zero.push_back(i-start);
            }else{
                i++;
            }
        }
        int sum=0;
        for(int i=1; i<zero.size(); i++){
            sum=max(sum,zero[i-1]+zero[i]);
        }
        return sum+activeCnt;
    }
};