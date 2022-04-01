/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) { 
        if (x < 0) return false;
        int num = x;
        long int reverse = 0;
        int ones = 0;
        while (num > 0) {
            ones = num % 10;
            // reverse = reverse * 10 + ones;
            // bit shift for faster mult? way faster, > 70%
            // same as reverse * 2^3 + reverse * 2 = reverse * 10
            reverse = (reverse << 3) + (reverse << 1) + ones;
            num = num / 10;
        }

        if (x == reverse) return true;
        return false;
    }

    // compare with reverse without array O(n) faster, 15-20%
    bool method2(int x) {
        return false;
    }; 

    // brute force, O(n/2 + n) = O(n) slow, below 10%
    bool method1(int x) {
        if (x < 0) return false; 
        std::vector<int> result;
        int num = x;
        while (num > 0) {
            result.push_back(num % 10);
            num /= 10;
        }

        for (int i = 0; i < result.size() / 2; i++) {
            if (result[i] != result[result.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

