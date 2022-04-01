/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // number of units have to match
        if (m * n != r * c) return mat;

        std::vector<vector<int>> result;
        int count_row = 0;
        int count_col = 0;

        std::vector<int> row;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                row.push_back(mat[i][j]);
                count_col++;
                if (count_col == c) {
                    result.push_back(row);
                    row = {};
                    count_col = 0;
                }
    
            }
        }
        
        return result;

    }
};
// @lc code=end

