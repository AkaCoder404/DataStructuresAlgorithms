/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    
        std::vector<std::string> result;
        // if (nums.size() == 1) {
        //     result.push_back(std::to_string(nums[0]));
        //     return result;
        // }
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            int j = i + 1;
            while(j < nums.size() && nums[j] == element + 1) {
                element++;
                j++;
            }
            std::string res = j == i + 1 ? std::to_string(element) : std::to_string(nums[i]) + "->" + std::to_string(nums[j - 1]);
            result.push_back(res);
            i = j - 1;
            
        }
        return result;
    }
};
// @lc code=end

