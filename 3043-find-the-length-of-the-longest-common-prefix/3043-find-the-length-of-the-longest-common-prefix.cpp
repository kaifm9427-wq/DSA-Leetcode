class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for(int x : arr1) {
            string s = to_string(x);

            string temp = "";

            for(char ch : s) {
                temp += ch;
                st.insert(temp);
            }
        }

        int maxi = 0;

        for(int x : arr2) {
            string s = to_string(x);

            string temp = "";

            for(char ch : s) {
                temp += ch;

                
                if(st.count(temp)) {
                    maxi = max(maxi, (int)temp.size());
                }
            }
        }

        return maxi;
    }
};