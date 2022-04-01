/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        // if num equals it self, then it means infinite loop
        do {
            int temp = 0;
            while(num != 0) {
                int mod = num % 10;
                temp += mod * mod;
                num /= 10;
            }
            num = temp;
            if (num == 1) return true;
        }
        while(num != 89); // magic number, whenever it hits 89, it loops
        return false;
        // while (num != n) {
        //     int temp = 0;
        //     while(num != 0) {
        //         int mod = num % 10;
        //         temp += mod * mod;
        //         num /= 10;
        //     }
        //     num = temp;
        //     if (num == 1) return true;
        // }
        // return false;
    }
};
// @lc code=end

