class Solution {
public:
    int numDistinct(string s, string t) {
        memo.assign(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t);
    }

private:
    vector<vector<int>> memo;

    // ways to match t[j..] using s[i..]
    int dfs(int i, int j, string& s, string& t) {
        if (j == t.size()) return 1;              // all of t matched
        if (i == s.size()) return 0;              // s exhausted, t remains

        if (memo[i][j] != -1) return memo[i][j];

        long ways = dfs(i + 1, j, s, t);          // skip s[i]
        if (s[i] == t[j])
            ways += dfs(i + 1, j + 1, s, t);      // match s[i] with t[j]

        return memo[i][j] = (int)ways;
    }
};