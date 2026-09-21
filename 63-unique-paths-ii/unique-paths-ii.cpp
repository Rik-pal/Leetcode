class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If start or end is blocked, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<long long> dp(n, 0);
        dp[0] = 1;  // starting position
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;  // obstacle: no paths through this cell
                } else if (j > 0) {
                    // paths from above (old dp[j]) + from left (new dp[j-1])
                    dp[j] += dp[j-1];
                }
                // j == 0: dp[0] keeps its value (first column, only from above)
            }
        }
        
        return (int)dp[n-1];
    }
};