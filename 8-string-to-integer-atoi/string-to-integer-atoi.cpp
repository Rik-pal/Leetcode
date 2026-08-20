class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Read digits
        int result = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // 4. Check overflow BEFORE result * 10
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {

                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;

            i++;
        }

        return result * sign;
    }
};