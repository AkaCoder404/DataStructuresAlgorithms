/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int front = 0;
        int back = 0;
        for(int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }

    }
};
// @lc code=end

