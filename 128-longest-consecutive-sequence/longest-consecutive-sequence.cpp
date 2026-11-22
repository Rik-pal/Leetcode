class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;

        for (int num : st) {
            // Only start counting at the beginning of a sequence
            if (!st.count(num - 1)) {
                int curr = num;
                int len = 1;
                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};