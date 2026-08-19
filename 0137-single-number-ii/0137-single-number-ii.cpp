class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int k=0; k<32; k++){
            int cntZero=0;
            int cntOne=0;
            int temp=1<<k;
            for(auto& it:nums){
                
                if((it & temp)==0){
                    cntZero++;
                }else{
                    cntOne++;
                }
            }
            if(cntOne%3==1){
                result=(result | temp);
            }
        }
        return result;
    }
};