class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs((30 * hour) - (5.5 * minutes));

        return (ans > 180) ? (360 - ans) : ans;
    }
};