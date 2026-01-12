class Solution {
public:
    //diagnol moves are min(|x2 - x1| , |y2 - y1|)
    //remaining distance -> max(horizontal distance, vertical distance)
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1; i<points.size(); i++)
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));

        return ans;   
    }
};