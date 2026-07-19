class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<bool> taken(26,false);
        vector<int> lastIndex(26);
        string result;
        for(int i=0; i<n; i++){
            char ch=s[i];
            int idx=ch-'a';
            lastIndex[idx]=i;
        }

        for(int i=0; i<n; i++){
            char ch=s[i];
            int idx=ch-'a';
            if(taken[idx]==true) continue;
            while(result.size()>0 && result.back()>ch && lastIndex[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            taken[idx]=true;
            result.push_back(ch);
        }
        return result;
    }
};