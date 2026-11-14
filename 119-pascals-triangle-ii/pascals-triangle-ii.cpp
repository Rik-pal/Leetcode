class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int j = 1; j <= rowIndex; j++)
            // C(n, j) = C(n, j-1) * (n - j + 1) / j
            row[j] = (long)row[j - 1] * (rowIndex - j + 1) / j;
        return row;
    }
};