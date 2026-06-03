class Solution {
public:
    long long solve(vector<int>& startA, vector<int>& durA,
                    vector<int>& startB, vector<int>& durB) {
        int m = startB.size();

        vector<pair<long long, long long>> ridesB;
        for (int i = 0; i < m; i++) {
            ridesB.push_back({startB[i], durB[i]});
        }

        sort(ridesB.begin(), ridesB.end());

        vector<long long> starts(m);
        for (int i = 0; i < m; i++) {
            starts[i] = ridesB[i].first;
        }

        vector<long long> prefMinDur(m);
        prefMinDur[0] = ridesB[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1], ridesB[i].second);
        }

        vector<long long> suffMinStartPlusDur(m);
        suffMinStartPlusDur[m - 1] =
            ridesB[m - 1].first + ridesB[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinStartPlusDur[i] =
                min(suffMinStartPlusDur[i + 1],
                    ridesB[i].first + ridesB[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)startA.size(); i++) {
            long long finishA = 1LL * startA[i] + durA[i];

            int idx = upper_bound(starts.begin(), starts.end(), finishA)
                      - starts.begin();

            if (idx > 0) {
                ans = min(ans, finishA + prefMinDur[idx - 1]);
            }

            if (idx < m) {
                ans = min(ans, suffMinStartPlusDur[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 = solve(landStartTime, landDuration,
                               waterStartTime, waterDuration);

        long long ans2 = solve(waterStartTime, waterDuration,
                               landStartTime, landDuration);

        return (int)min(ans1, ans2);
    }
};