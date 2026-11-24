class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size(), n = board[0].size();

        // Step 1: mark all O's connected to the border
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);       // left column
            dfs(board, i, n - 1);   // right column
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);       // top row
            dfs(board, m - 1, j);   // bottom row
        }

        // Step 2: flip surrounded O's, restore marked ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    int m, n;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        board[r][c] = '#';  // mark as safe
        for (auto& d : dirs) dfs(board, r + d[0], c + d[1]);
    }
};