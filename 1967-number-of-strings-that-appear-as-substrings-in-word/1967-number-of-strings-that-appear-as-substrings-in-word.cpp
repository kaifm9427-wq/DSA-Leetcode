class Solution {
public:
    bool checkSubstr(string& patterns, string& str){
    int n = patterns.size();
    if(n > str.size()){
        return false;
    }
    for(int i = 0; i <= str.size() - n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(patterns[j] == str[i + j]){
                cnt++;
            }else{
                break;
            }
        }
        if(cnt == n){
            return true;
        }
    }

    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            bool check=checkSubstr(patterns[i],word);
            if(check){
                cnt++;
            }
        }
        return cnt;
    }
};