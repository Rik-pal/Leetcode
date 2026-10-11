class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // One way: the empty tree
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)          // trees with i nodes
            for (int j = 1; j <= i; ++j)      // choose root j
                dp[i] += dp[j - 1] * dp[i - j];

        return dp[n];
    }
};