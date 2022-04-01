/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int pos = digits.size() - 1;
        while (carry == 1 && pos >= 0) {
            int sum = digits[pos] + carry;
            digits[pos] = sum % 10;
            carry = sum / 10;
            pos--;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;

    }
};
// @lc code=end

