/*
 * @lc app=leetcode.cn id=2078 lang=cpp
 *
 * [2078] 两栋颜色不同且距离最远的房子
 */

// @lc code=start
class Solution {
public:
    int abs(int x) {
        if (x < 0) return -1 * x;
        return x;
    }
    int maxDistance(vector<int>& colors) {
        // method 1: brute force O(n^2) and O(1)
        // int max = 1;
        // for (int i = 0; i < colors.size(); i++) {
        //     for (int j = i + 1; j < colors.size(); j++) {
        //         if (colors[i] != colors[j] && abs(i-j) > max) {
        //             max = abs(i-j);
        //         }   
        //     }
        // }
        // return max;

        // method 2: greedy O(n)
        // because there are at least 2 colors, there must be a color different from index 0 and index 1
        // the optimal answer must be one of either
        int max = 0;
        // max distance from the right
        for (int i = colors.size() - 1; i > 0; i--) {
            if (colors[0] != colors[i]) {
                max = abs(i);
                break;
            }
        }
        // printf("%d\n", max);
        // max distance from the left
        for (int i = 0; i < colors.size(); i++ ) {
            if (colors[colors.size() - 1] != colors[i]) {
                if (max < colors.size() - 1 - i) {
                    max = colors.size() - 1 - i;
                    break;
                }
            }
        }
        return max;

    }
};
// @lc code=end

