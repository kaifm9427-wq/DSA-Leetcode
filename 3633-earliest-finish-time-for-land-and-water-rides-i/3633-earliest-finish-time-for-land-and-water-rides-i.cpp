class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;


        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int startWater = max(landFinish, waterStartTime[j]); 
                ans = min(ans, startWater + waterDuration[j]);
            }
        }

   
        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int startLand = max(waterFinish, landStartTime[j]); 
                ans = min(ans, startLand + landDuration[j]);
            }
        }

        return ans;
    }
};