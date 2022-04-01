/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
#include <math.h>
class Solution {
public:
    bool isPowerOfFour(int n) {
        // power four is just log2(log2(x))
        // if(n == 1 || n == 64) return true;
        // if(n == 0 || n == 2) return false;

        // if (n == 1) return true;
    
    
        // float x = log2(log2(n));
        // return floor(log2(log2(n))) == log2(log2(n));       


        // first check power of 2, because all poewr of 4 are power of 2
        // power of 4 only happens on odd bits, so check with 0x5 = 0b101
        
        if (n < 0 || (n & -n) != n ) return false;
        return n & 0x55555555;//check 1 on odd bits
    }
};
// @lc code=end

