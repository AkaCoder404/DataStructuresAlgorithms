/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include <unordered_set> 
#include <unordered_map>
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); i++) {
            auto it = hashmap.find(s[i]);
            if (it != hashmap.end()) hashmap[s[i]]++;
            else hashmap[s[i]] = 1;
        }

        for (int i = 0; i < t.size(); i++) {
            auto it = hashmap.find(t[i]);
            // if doesn't exist 
            if (it == hashmap.end()) return t[i];
            // exists but no more matches
            else if (hashmap[t[i]] == 0) return t[i];
            else hashmap[t[i]]--; 
        }
        return t[0];

    }
};
// @lc code=end

