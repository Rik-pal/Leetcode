class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        heights.push_back(0);  // sentinel to flush the stack
        std::stack<int> stk;   // stores indices, heights increasing
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                // width: between previous smaller bar and current bar
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = std::max(maxArea, h * width);
            }
            stk.push(i);
        }

        return maxArea;
    }
};