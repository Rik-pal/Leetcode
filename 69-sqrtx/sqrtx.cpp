class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  // sqrt(0)=0, sqrt(1)=1
        
        int left = 1, right = x / 2;  // answer can't exceed x/2 for x >= 2
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // avoid overflow
            long long square = (long long)mid * mid;  // avoid overflow!
            
            if (square == x) {
                return mid;           // perfect square
            } else if (square < x) {
                ans = mid;            // mid is a candidate, try larger
                left = mid + 1;
            } else {
                right = mid - 1;      // too big, go smaller
            }
        }
        
        return ans;  // last valid candidate (floor of sqrt)
    }
};