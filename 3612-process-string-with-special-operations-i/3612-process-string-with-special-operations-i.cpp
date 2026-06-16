class Solution {
public:
    string processStr(string s) {
        string res;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            } else if (s[i] == '#') {
                if (!res.empty()) {
                    res += res;    
                }
            } else if (s[i] == '%') {
                reverse(res.begin(), res.end());
            } else {
                res += s[i];
            }
        }

        return res;
    }
};