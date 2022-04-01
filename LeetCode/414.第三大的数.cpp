/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());

        // if (nums.size() < 3) return nums[0];

        
        // std::vector<int> result = {nums[0]};
        // for(int i = 1; i < nums.size(); i++) {
        //    if(result[result.size() - 1] == nums[i]) continue;
        //    result.push_back(nums[i]);
        // }

        // return result.size() > 2 ? result[2] : result[0];
        int first = -2147483648;
        bool first_update = false;
        int second = -2147483648;
        bool second_update = false;
        int third = -2147483648;
        bool third_update = false;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (first < nums[i]) {
                first = nums[i];
                first_update = true;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if (second < nums[i] && nums[i] < first) second = nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            if (third <= nums[i] && nums[i] < first && nums[i] < second) {
                third = nums[i];
                third_update = true;
            }
        }

        return third_update ? third : first;
    }
};
// @lc code=end

