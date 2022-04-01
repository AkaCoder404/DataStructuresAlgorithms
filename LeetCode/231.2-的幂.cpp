/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
#include <math.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if odd
        // if (n % 2 == 1) return false; 
        // all powers of two have only 1 bit that is 1, at the highest bit
        // 1 1
        // 2 10
        // 4 100
        // 8 1000
        // if(n == 0) return false;
        // return floor(log2(n)) == log2(n);  


        // method 3
        return (n > 0) && (n & -n) == n;

        // 移位运算：把二进制数进行左右移位。左移1位，扩大2倍；右移1位，缩小2倍p
        // return (n>0) && (1<<30) % n == 0;
        // 1<<30得到最大的2的整数次幂，对n取模如果等于0，说明n只有因子2, 所以n只有因子
    }

    // method 1 // recursively divide by 2, and check if it equals 1 at the end
    // method 2 // use log and floor to check if even number
    // method 3 // bit manipulation
};
// @lc code=end

