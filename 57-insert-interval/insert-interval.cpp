class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Phase 1: Add all intervals that end BEFORE newInterval starts
        // (no overlap possible with these)
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Phase 2: Merge all intervals that OVERLAP with newInterval
        // Overlap condition: interval starts before or at newInterval's end
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);  // extend start
            newInterval[1] = max(newInterval[1], intervals[i][1]);  // extend end
            i++;
        }
        result.push_back(newInterval);  // add the (possibly expanded) merged interval
        
        // Phase 3: Add all remaining intervals (they start AFTER newInterval ends)
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};