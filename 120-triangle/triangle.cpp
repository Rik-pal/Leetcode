class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Start with the bottom row — dp = copy of last row
        vector<int> dp = triangle.back();

        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int j = 0; j <= r; j++) {
                dp[j] = triangle[r][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};