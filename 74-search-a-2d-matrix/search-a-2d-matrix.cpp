class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Convert 1D index to 2D coordinates
            int row = mid / n;      // integer division gives row
            int col = mid % n;      // remainder gives column
            
            int value = matrix[row][col];
            
            if (value == target) {
                return true;
            } else if (value < target) {
                left = mid + 1;   // search right half
            } else {
                right = mid - 1;  // search left half
            }
        }
        
        return false;
    }
};