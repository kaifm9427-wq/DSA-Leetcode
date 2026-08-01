class Solution {
public:
    int func(int ind,vector<int>& nums,int j){
        if(ind==j) return nums[ind];
        int player1=nums[ind]-func(ind+1,nums,j);
        int player2=nums[j]-func(ind,nums,j-1);
        return max(player1,player2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return func(0,nums,n-1)>=0;
    }
};