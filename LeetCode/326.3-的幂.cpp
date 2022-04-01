/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // brute force method
        // while (n % 3 == 0) {
        //     n /= 3;
        // }
        // return n == 1;
        // largest power of 3 that fits the 32 bit integer
        return n > 0 && 1162261467 % n == 0;
    }
};
// @lc code=end

