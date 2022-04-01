/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int total = 0;
    int recursion(int steps, int target) {
        // too many steps
        if (steps > target) {
            return 0;
        }
        // hits targeet, return + 
        if (steps == target) {
            return 1;
        }
        // return number of 1 step or 2 steps
        return recursion(steps + 1, target) + recursion(steps + 2, target); 
    }



    int climbStairs(int n) {
        std::vector<int> results;
        // [0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144]
        if (n == 1) return 1; 
        if (n == 2) return 2;
    
        results.push_back(1);
        results.push_back(2);

        for (int i = 2; i < n; i++) {
            results.push_back(results[i - 1] + results[i - 2]);
        }
        return results[n - 1];  
        // return recursion(0, n);
    }

    // method1 recursively make tree and find paths that add up to target
    // use memory for recursive a_n = a_n - 1 a_n-2
};
// @lc code=end

