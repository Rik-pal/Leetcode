class Solution {
public:
    int uniquePaths(int m, int n) {
        // Total moves: (m-1) down + (n-1) right = m+n-2 moves
        // Answer = C(m+n-2, m-1) = C(m+n-2, n-1)
        
        // Choose the smaller of (m-1, n-1) to minimize iterations
        int k = min(m - 1, n - 1);
        long long result = 1;
        
        for (int i = 1; i <= k; i++) {
            result = result * (m + n - 1 - i) / i;
        }
        
        return (int)result;
    }
};