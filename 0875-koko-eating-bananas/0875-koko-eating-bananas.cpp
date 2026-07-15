class Solution {
public:
    bool canEatAll(vector<int>& piles,int mid,int h){
        int hrs=0;
        for(auto& it:piles){
            hrs=hrs+it/mid;
            if(it%mid!=0){
                hrs++;
            }
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(), piles.end());

        while(l<r){
            int mid=l+(r-l)/2;
            if(canEatAll(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};