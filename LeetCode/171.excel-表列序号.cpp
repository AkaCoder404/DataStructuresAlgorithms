/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        // start from end
        int pos = columnTitle.length() - 1;
        // track current int value
        int cur_sum = 0;
        long int mult = 1;
        while(pos >= 0) {
            int val = (int(columnTitle[pos] - 64));
            cur_sum += val * mult;
            mult *= 26;
            pos--;
        }
        return cur_sum;
    }
};
// @lc code=end

