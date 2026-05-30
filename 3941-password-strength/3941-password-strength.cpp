class Solution {
public:
    int passwordStrength(string password) {
        int points=0;
        set<char> pass(password.begin(), password.end());
        for(auto& it:pass){
            if(islower(it)){
                points+=1;
            }else if(isupper(it)){
                points+=2;
            }else if(isdigit(it)){
                points+=3;
            }else{
                points+=5;
            }
        }
        return points;
    }
};