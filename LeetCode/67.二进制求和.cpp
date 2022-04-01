/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) swap(a, b); // longer string first

        int len_a = a.length();
        int len_b = b.length();
        
        int sum;
        int carry = 0;
        std::string result;

        // add all digits of shorter string
        for (int i = len_b - 1; i >= 0; i--) {
            sum = (a[i + (len_a - len_b)] - '0') + (b[i] - '0') + carry;
            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
        }

        // rest of the longer string
        for(int i = len_a - len_b - 1; i >= 0; i--) {
            sum = (a[i] - '0') + carry;
            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
        }


        // if leading carry
        if (carry == 1) result = '1' + result;

        // reverse result
        // for (int i = 0; i < result.length() / 2; i++) {
        //     char temp = result[i];
        //     result[i] = result[result.length() - 1 - i];
        //     result[result.length() - 1 - i] = temp; 
        // }
        return result;
        
    }
};
// @lc code=end

