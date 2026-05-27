class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> firstOccur(27,-1);
        vector<int> lastOccur(27,-1);
        for(int i=0; i<n; i++){
            if(islower(word[i])){
                lastOccur[word[i]-'a']=i;
            }else{
                if(firstOccur[word[i]-'A']==-1){
                    firstOccur[word[i]-'A']=i;
                }  
            }
        }
        int cnt=0;
        for(int i=0; i<27; i++){
            if(lastOccur[i]!=-1 && firstOccur[i]!=-1 && lastOccur[i]<firstOccur[i]){
                cnt++;
            }
        }
        return cnt;
    }
};