/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result;
        //  num1 is larger 
        if (num1.length() < num2.length()) swap(num1, num2);

        int j = num1.length() - 1;
        int carry = 0;
        for (int i = num2.length() - 1; i >= 0; i--, j--) {
            int sum = (num1[j] - '0') + (num2[i] - '0') + carry;
            result = to_string(sum % 10) + result; 
            carry = sum / 10;
        }
        // rest of j
        for (; j >= 0; j--) {
            int sum = (num1[j] - '0') + carry;
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        if (carry) result = "1" + result;
        return result;
    }
};
// @lc code=end

