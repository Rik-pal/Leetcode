class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        
        // Skip trailing spaces (e.g., "moon  ")
        while (i >= 0 && s[i] == ' ')
            i--;
        
        // Count the word characters
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};