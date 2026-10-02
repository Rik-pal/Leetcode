class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
            }
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    // Same monotonic stack from the previous problem
    int largestRectangleArea(std::vector<int>& heights) {
        heights.push_back(0);              // sentinel
        std::stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i < (int)heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = std::max(maxArea, h * width);
            }
            stk.push(i);
        }

        heights.pop_back();                // clean up sentinel
        return maxArea;
    }
};