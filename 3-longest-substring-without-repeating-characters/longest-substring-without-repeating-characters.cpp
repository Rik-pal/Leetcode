class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);

        int left = 0;
        int right = 0;
        int maxLen = 0;

        for (right = 0; right < s.size(); right++) {
            char c = s[right];

            if (hash[c] >= left) {
                left = hash[c] + 1;
            }

            hash[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};