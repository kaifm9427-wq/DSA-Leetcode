class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> l(27,false);
        vector<bool> u(27,false);

        for(auto it:word){
            if(islower(it)){
                l[it-'a']=true;
            }else{
                u[it-'A']=true;
            }
        }


        int cnt=0;
        for(int i=0; i<27; i++){
            if(l[i] && u[i]){
                cnt++;
            }
        }
        return cnt;
    }
};