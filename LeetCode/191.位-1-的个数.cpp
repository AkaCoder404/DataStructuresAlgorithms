/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // The Hamming distance of two words A and B can be calculated as the Hamming weight of A xor B
        // check wikipedia for more types of algorithms to determin hamming weight
        
        // good when low number of ones
        // the bitwise AND of x with x − 1 differs from x only in zeroing out the least significant nonzero bit: 
        // subtracting 1 changes the rightmost string of 0s to 1s, 
        // and changes the rightmost 1 to a 0. 
        // if x originally had n bits that were 1, 
        // then after only n iterations of this operation, 
        // x will be reduced to zero. 
        int i;
        // stop when n == 0;
        for(i = 0; n; i++) {
            n = n & (n-1);
        }
        return i;
    }
};
// @lc code=end

