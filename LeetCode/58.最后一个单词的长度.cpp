/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length() - 1; 
        while(length >= 0 && s[length] == ' ') {
            length--;
        }

        int count = 0;
        while(length >= 0 && s[length] != ' ') {
            length--;
            count++;
        }
        return count;

    }
};
// @lc code=end

// "   fly me   to   the moon  " 
// "luffy is still joyboy" 