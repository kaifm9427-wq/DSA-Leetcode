class Solution {
public:
    string convertToTitle(int columnNumber) {
        char hash[27];
        for(int i=0; i<26; i++){
            hash[i]='A'+i;
        }
        string ans="";
        while(columnNumber){
            columnNumber--;
            int dig=columnNumber%26;
            ans=ans+hash[dig];
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};