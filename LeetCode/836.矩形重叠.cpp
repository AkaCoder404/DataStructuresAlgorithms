/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // int rect1_left = rec1[0];
        // int rect1_right = rec1[0] + rec1[2];
        // int rect1_top = rec1[1];
        // int rect1_bottom = rec1[1] + rec1[3];

        // int rect2_left = rec2[0];
        // int rect2_right = rec2[0] + rec2[2];
        // int rect2_top = rec2[1];
        // int rect2_bottom = rec2[1] + rec2[3];

        // int x_overlap = max(0, min(rect1_right, rect2_right) - max(rect1_left, rect2_left));
        // int y_overlap = max(0, min(rect1_bottom, rect2_bottom) - max(rect1_top, rect2_top));
        // printf("%d", x_overlap * y_overlap);
        // return x_overlap * y_overlap == 0 ? false : true;
        // project onto x and y axis and see if overlap
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));
    }
};
// @lc code=end

