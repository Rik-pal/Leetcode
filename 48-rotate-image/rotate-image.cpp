class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Reverse vertically (upside down)
        reverse(matrix.begin(), matrix.end());
        // Transpose
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};