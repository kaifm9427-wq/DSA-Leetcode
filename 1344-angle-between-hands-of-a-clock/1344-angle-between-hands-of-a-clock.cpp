class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr=0;
        if(hour==12) hr=0;
        else hr=hour;
        double hrPoint=hr+minutes/60.0;
        double hrDegree=hrPoint*30;
        double minDegree=minutes*6;
        double ans=abs(hrDegree-minDegree);
        return min(ans,360-ans);
    }
};