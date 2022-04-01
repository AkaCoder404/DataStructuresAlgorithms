/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        // runtime above 60%, memory above 72.73
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'I') {
                if (s[i + 1] == 'I') {
                    if (s[i + 2] == 'I') {
                        sum += 3;
                        i += 2;
                    }
                    else {
                        sum += 2; 
                        i+= 1;
                    }
                }
                else if (s[i + 1] == 'V') {
                    sum += 4;
                    i += 1;
                }
                else if (s[i + 1] == 'X') {
                    sum += 9;
                    i += 1;
                }        
                else sum += 1;
            }
            else if (c == 'X') {
                if (s[i + 1] == 'L') {
                    sum += 40;
                    i += 1;
                }
                else if (s[i + 1] == 'C') {
                    sum += 90;
                    i += 1;
                }
                else sum += 10;
            }
            else if (c == 'C') {
                if (s[i + 1] == 'D') {
                    sum += 400;
                    i += 1;
                }
                else if (s[i + 1] == 'M') {
                    sum += 900;
                    i += 1;
                }
                else sum += 100;
            }
            else if (c == 'M') {
                sum += 1000;
            }
            else if (c == 'L') sum += 50;
            else if (c == 'V') sum += 5;
            else if (c == 'D') sum += 500;
        }
        return sum;
    }
    

    // I, II, III, V, X, L, C, D, M
    // IV, IX
    // XL, XC
    // CD, CM
};
// @lc code=end

