/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int makeeven(int number) {
        if (number < 0) return -1 * number;
        return number;
    }
    int pivotIndex(vector<int>& nums) {
        // int leftsum = 0;
        // int rightsum = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     leftsum = 0; 
        //     rightsum = 0;
        //     for (int j = 0; j < i; j++) {
        //         leftsum += nums[j];
        //     }
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         rightsum += nums[j];
        //     }
        //     if ( leftsum == rightsum ) return i;
        //     // printf("%d %d\n", leftsum, rightsum);
        // }
        // return -1;

        // two pointer method from left right
        // int leftpointer, rightpointer;
        // leftpointer = -1;
        // rightpointer = nums.size();
        // int leftsum = 0;
        // int rightsum = 0;
        // while(rightpointer - leftpointer > 2) {
        //     if (leftsum < rightsum) {
        //         leftsum += nums[++leftpointer];
        //     } else {
        //         rightsum += nums[--rightpointer];
        //     }
        // }
        // printf("%d %d", leftsum, rightsum);
        // return leftsum == rightsum ? (leftpointer + rightpointer) / 2 : -1;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

