class Solution {
public:
    string countAndSay(int n) {
        string current = "1";

        // Build the sequence from 2 up to n
        for (int i = 2; i <= n; ++i) {
            string next;
            int len = current.size();

            for (int j = 0; j < len; ) {
                char digit = current[j];
                int count = 0;

                // Count consecutive identical digits
                while (j < len && current[j] == digit) {
                    ++count;
                    ++j;
                }

                next += to_string(count);
                next += digit;
            }

            current = move(next);
        }

        return current;
    }
};