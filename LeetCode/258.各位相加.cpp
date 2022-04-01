/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {

        // we know that multiple of nines
        // if (num / 10 == 0) return num; // single digit
        // while (num > 9) {
        //     num -= 9;
        // }
        // return num;   

        // wait, if we keep subtrating 9, why don't we just use modulus
        if (num / 10 == 0) return num;
        num = num % 9;
        if (num == 0) return 9;
        return num;
    }

    // 1 10 19 28 37 46 55 64 73 82 91 100
    // 2 11 20 29 38 47 56 65 74 83 92

    // 3 12 21 30 39
    // 4 13 22 31 40
};
// @lc code=end

