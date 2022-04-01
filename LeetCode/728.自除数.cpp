/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    bool is_self_dividing(int number) {
        int orig = number;
        while (number > 0) {
            int mod = number % 10;
            if (mod == 0 || orig % mod != 0) return false;
            number = number / 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> results;
        for (int i = left; i <= right; i++) {
            if (i % 10 == 0) continue;
            // else if (i < 10) results.push_back(i);
            else if (is_self_dividing(i)) {
                results.push_back(i);
            }

        }

        return results;

    }
    
};
// @lc code=end

