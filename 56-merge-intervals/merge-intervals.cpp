class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        for (const auto& interval : intervals) {
            // If result is empty OR current interval doesn't overlap with the last one
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);          // No overlap: add as new interval
            } else {
                // Overlap: merge by extending the end of the last interval
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        
        return result;
    }
};