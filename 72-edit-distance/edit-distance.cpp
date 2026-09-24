class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        // dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases: converting to/from empty string
        for (int i = 0; i <= m; i++) dp[i][0] = i;  // delete all i characters
        for (int j = 0; j <= n; j++) dp[0][j] = j;  // insert all j characters
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // Characters match: no operation needed
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Take the minimum of three operations:
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Delete word1[i-1]
                        dp[i][j-1],     // Insert word2[j-1]
                        dp[i-1][j-1]    // Replace word1[i-1] with word2[j-1]
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};