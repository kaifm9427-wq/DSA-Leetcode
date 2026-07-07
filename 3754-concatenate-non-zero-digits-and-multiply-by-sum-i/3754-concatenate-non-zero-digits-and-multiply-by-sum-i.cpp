class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        string s="";
        while(n){
            int dig=n%10;
            sum+=dig;
            if(dig!=0){
                s+=to_string(dig);
            }
            n=n/10;
        }
        reverse(s.begin(),s.end());
        long long x = s.empty() ? 0 : stoll(s);
        return x*sum;

    }
};