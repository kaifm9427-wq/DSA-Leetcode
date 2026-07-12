class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};