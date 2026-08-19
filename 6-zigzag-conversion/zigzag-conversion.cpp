class Solution {
public:
    string convert(string s, int numRows) {

        // If only one row, no zigzag is possible
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (char c : s) {

            rows[row] += c;

            // Reached bottom
            if (row == numRows - 1)
                direction = -1;

            // Reached top
            else if (row == 0)
                direction = 1;

            row += direction;
        }

        string answer;

        for (string r : rows)
            answer += r;

        return answer;
    }
};