class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, i, j, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, 
                   int i, int j, int index) {
        // Base case: found all characters
        if (index == word.size())
            return true;
        
        // Boundary check and character match check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[index])
            return false;
        
        // Mark as visited (modify in-place)
        char temp = board[i][j];
        board[i][j] = '#';  // '#' won't match any letter
        
        // Explore 4 directions
        bool found = backtrack(board, word, i + 1, j, index + 1) ||  // down
                     backtrack(board, word, i - 1, j, index + 1) ||  // up
                     backtrack(board, word, i, j + 1, index + 1) ||  // right
                     backtrack(board, word, i, j - 1, index + 1);    // left
        
        // Backtrack: restore the cell
        board[i][j] = temp;
        
        return found;
    }
};