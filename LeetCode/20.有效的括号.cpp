/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> pairs; 
        pairs.insert({'(', ')'});
        pairs.insert({'[', ']'});
        pairs.insert({'{', '}'});

        int pos = 0;
        while (s.length() > 0) {
            char c = s[pos];
            if (s[pos] == ']' || s[pos] == '}' || s[pos] == ')') {
                if (pos == 0) return false;
                char c_left = s[pos - 1];
                if (pairs[c_left] != c) return false; // inner most don't match 
                else {
                    s = s.erase(pos - 1, 2); // [first, last)
                    pos -= 1;
                    continue;
                }
            }
            pos++;
            if (pos > s.length()) return false;
        }
        return true;
    }
};
// @lc code=end

