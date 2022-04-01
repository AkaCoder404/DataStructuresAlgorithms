/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    // had one result that beat 100% of submissions lol
    string longestCommonPrefix(vector<string>& strs) {
        std::string substr = "";
        for(int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return substr;
                }
            }
            substr += c;
        }
        return substr;
    }
};
// @lc code=end

