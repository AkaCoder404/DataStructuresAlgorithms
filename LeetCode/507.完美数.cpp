/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // method1
        // std::vector<int> factors;
        // for (int i = 1; i <= num / 2; i++) {
        //     if (num % i == 0) factors.push_back(i); 
        // }

        // int sum = 0;
        // for(int i = 0; i < factors.size(); i++) {
        //     sum += factors[i];
        // }
        
        // return sum == num;

        // method2 
        // int sum = 0;
        // for (int i = 1; i <= num/2; i++) {
        //     if (num % i == 0) sum += i;
        // }
        // return sum == num;

        if (num % 2 == 1) return false;
        if (num == 6 ||
            num == 8 ||
            num == 28 || 
            num == 496 ||
            num == 8128 || 
            num == 33550336) return true;
        return false;


    }

    // method 1






};
// @lc code=end

