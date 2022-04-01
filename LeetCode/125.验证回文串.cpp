/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125]) 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {

        int front = 0;
        int back = s.length() - 1;
        while (front <= back) {
            // if (tolower(s[front]) <= 'a' || tolower(s[front]) >= 'z') {
            //     front++;
            //     continue;
            // }
            // if (tolower(s[back]) <= 'a' || tolower(s[back]) >= 'z') {
            //     back--;
            //     continue;
            // }
            // if (tolower(s[front]) == tolower(s[back])) {
            //     front++;
            //     back--;
            // }
            // else return false;
            
            // skip if character if not within 0 to 9 or A to Z or A to Z
            if (!((s[front] >= '0' && s[front] <= '9')  || (s[front] >= 'a' && s[front] <= 'z') || (s[front] >= 'A' && s[front] <= 'Z'))) {
                front++;
                continue;

            }
            if (!((s[back] >= '0' && s[back] <= '9')  || (s[back] >= 'a' && s[back] <= 'z') || (s[back] >= 'A' && s[back] <= 'Z'))) {
                back--;
                continue;
            }
            if (tolower(s[front]) == tolower(s[back])) {
                front++;
                back--;
            }
            else return false;
        }
        return true;

    }
};
// @lc code=end

