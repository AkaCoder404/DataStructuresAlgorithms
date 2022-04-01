/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int candy_type_count = 0;
        int candy_amount = candyType.size();
        std::unordered_set<int> hashmap;
        for(int i = 0; i < candy_amount; i++) {
            if (hashmap.find(candyType[i]) != hashmap.end()) continue;
            candy_type_count++;
            hashmap.insert({candyType[i]}); 
        }   
        int half = candy_amount >> 1;
        return candy_type_count < half ? candy_type_count : half;
    }
};
// @lc code=end

