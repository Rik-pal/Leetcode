class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, minPrefix = 0, ans = INT_MIN;
        for (int num : nums) {
            sum += num;
            ans = max(ans, sum - minPrefix);
            minPrefix = min(minPrefix, sum);
        }
        return ans;
    }
};