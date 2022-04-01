/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        return ~(-num);

        // ~ bitwise comp of integer n is equal to -(n+1)
        // 1's comp changes 0 to 1 and vice versa
        // 2's comp
        // The 2's complement of a number N gives -N.
        // add 1 to the result of the 1's comp to get 2's complement of the original number. 
    }
};

// method 1 convert to binary, switch 
// @lc code=end

