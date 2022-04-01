/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
#include <unordered_map>

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // method 1 hashmap O(n + m), O(n + m)
        // std::unordered_map<std::string, int> hashmap;
        // int totalCount = 0;

        // // insert words1 into hashmap, count repeats <word, count
        // for (int i = 0; i < words1.size(); i++) {
        //     auto find = hashmap.find(words1[i]);
        //     if (find != hashmap.end()) hashmap[words1[i]]++;
        //     else hashmap[words1[i]] = 1;

        // }

        // // check words2, if word exists, update count
        // for (int i = 0; i < words2.size(); i++) {
        //     auto find = hashmap.find(words2[i]);
        //     if (find != hashmap.end()) hashmap[words2[i]]++;
        // }

        // // only if count is 2, update totalCount
        // for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
        //     if (it->second == 2) totalCount++;
        // }
        // return totalCount; 

        std::unordered_map<string, int> freq1, freq2;   // words1 和 words2 中字符串的出现次数
        for (const string& word1: words1){
            ++freq1[word1];
        }
        for (const string& word2: words2){
            ++freq2[word2];
        }
        int res = 0;   // 出现过一次的公共字符串个数
        for (const auto& [word1, cnt1] : freq1){
            // 遍历 words1 出现的字符并判断是否满足要求
            if (cnt1 == 1 && freq2[word1] == 1){
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

