/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start

class Solution {
public:
    // char upper case 65-90, A-Z
    string convertToTitle(int columnNumber) {
        string columnName = "";
        while (columnNumber > 0){
            int modulo = (columnNumber - 1) % 26;
            columnName = char('A' + modulo) + columnName;
            columnNumber = (columnNumber - modulo) / 26;
        } 
        return columnName; 
    }
    // 1
    // 701
    // 58
};
// @lc code=end

