/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            vector<int> row(n);
            result.push_back(row);
            for (int j = 0; j < n; j++) {
                // top left corner
                if (i == 0 && j == 0) {
                    int sum = img[i][j] + img[i][j + 1] + img[i+1][j+1] + img[i+1][j];
                    result[i][j] = sum / 4;
                }
                // top right corner

                else if (i == 0 && j == n - 1) {
                    int sum = img[i][j] + img[i][j-1] + img[i+1][j] + img[i+1][j-1];
                    result[i][j] = sum / 4;
                }

                // bottom left corner
                else if (i == m - 1 && j == 0) {
                    int sum = img[i][j] + img[i-1][j] + img[i][j+1] + img[i-1][j+1];
                    result[i][j] = sum / 4;
                }

                // bottom right corner
                else if (i == m - 1 && j == n - 1) {
                    int sum = img[i][j] + img[i-1][j-1] + img[i][j-1] + img[i-1][j];
                    result[i][j] = sum / 4;
                }

                // top row
                else if (i == 0) {
                    int sum = img[i][j] + img[i][j+1] + img[i][j - 1] + img[i+1][j] + img[i+1][j+1] + img[i+1][j-1];
                    result[i][j] = sum / 6;
                }


                // right col
                else if (j == n - 1) {
                    int sum = img[i][j] + img[i+1][j] + img[i-1][j] + img[i][j - 1] + img[i-1][j-1] + img[i+1][j-1];
                    result[i][j] = sum / 6;
                }

                // bot row
                else if (i == m - 1) {
                    int sum = img[i][j] + img[i-1][j] + img[i-1][j-1] + img[i-1][j+1] + img[i][j-1] + img[i][j+1];
                    result[i][j] = sum / 6;
                }

                // left col
                else if (j == 0) {
                    int sum = img[i][j] + img[i-1][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1] + img[i-1][j+1];
                    result[i][j] = sum / 6;
                }

                else {
                    // middle
                    int sum = img[i][j] + img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j + 1] + img[i + 1][j + 1] + img[i + 1][j] + img[i+1][j-1]  + img[i][j - 1];
                    result[i][j] = sum / 9;     
                }
                
            }
        }

        return result;
    }
};
// @lc code=end

