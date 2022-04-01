/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> foward;      // store forward mapping
        std::unordered_map<char, char> backwards;   // store backward mapping
        for (int i = 0; i < s.length(); i++) {
            auto find = foward.find(s[i]);
            // if mapping doesn't exists
            if (find == foward.end()) {
                foward[s[i]] = t[i];                   // create forward mapping
                auto findBack = backwards.find(t[i]); 
                // if backward mapping already exists and its mapping to a different one, error
                if (findBack != backwards.end() and backwards[t[i]] != s[i]) {
                    return false;
                }
                backwards[t[i]] = s[i];
              
            }
            else if (find->second != t[i]) return false;
        }
        return true;

    }
};
// @lc code=end

