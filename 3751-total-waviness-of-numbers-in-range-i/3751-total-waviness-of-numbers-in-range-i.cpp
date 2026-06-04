class Solution {
public:
    int sizeNum(int n){
        if(n==0) return 1;
        int cnt=0;
        while(n){
            cnt++;   
            n=n/10;
        }
        return cnt;
    }

    vector<int> convertArr(int n){
        vector<int> arr;
        if(n==0){
            arr.push_back(0);
            return arr;
        }
        while(n){
            int dig=n%10;
            arr.push_back(dig);
            n=n/10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }

    int solve(int n) {
        vector<int> arr = convertArr(n);
        int sz = arr.size();
        int cnt = 0;
        for (int i = 1; i < sz - 1; i++) {
            if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
                (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
                cnt++;
            }
        }
        return cnt;

    }
    int totalWaviness(int num1, int num2) {
        int result=0;
        for(int i=num1; i<=num2; i++){
            result=result+solve(i);
        }
        return result;
    }
};