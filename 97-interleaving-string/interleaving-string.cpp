class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size(), n = s2.size();
        // dp[i][j] = -1 unknown, 0 false, 1 true
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }

private:
    bool dfs(const string& s1, const string& s2, const string& s3,
             int i, int j, vector<vector<int>>& dp) {
        if (i + j == s3.size()) return true;      // Both strings fully consumed
        if (dp[i][j] != -1) return dp[i][j];

        bool ok = false;
        // Take next char from s1 (must match s3[i+j])
        if (i < s1.size() && s1[i] == s3[i + j] &&
            dfs(s1, s2, s3, i + 1, j, dp))
            ok = true;
        // Take next char from s2
        else if (j < s2.size() && s2[j] == s3[i + j] &&
                 dfs(s1, s2, s3, i, j + 1, dp))
            ok = true;

        return dp[i][j] = ok;
    }
};