/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
public:
    double abs(double x) {
        if (x < 0) return -1 * x;
        else return x;
    }
    double shoelace_area (int xa, int ya, int xb, int yb, int xc, int yc) {
        return abs(0.5 * ((xa - xc) * (yb - ya) - (xa - xb) * (yc - ya)));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        for (int i = 0; i < points.size() - 2; i++) {
            for (int j = i + 1; j < points.size() - 1; j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double curr_area = shoelace_area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                    if (curr_area > area) area = curr_area;
                }
            }
        }
        return area;
    }
};
// @lc code=end

