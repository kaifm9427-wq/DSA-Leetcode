class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long currMass=mass;
        int n=asteroids.size();
        for(int i=0; i<n; i++){
            if(currMass>=asteroids[i]){
                currMass=currMass+asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};