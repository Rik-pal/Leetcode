class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
    
private:
    void backtrack(int start, int n, int k, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: we've picked k numbers
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Try each number from 'start' to n
        // (starting from 'start' avoids duplicates like [1,2] and [2,1])
        for (int i = start; i <= n; i++) {
            current.push_back(i);           // Choose i
            backtrack(i + 1, n, k, current, result);  // Explore with i chosen
            current.pop_back();             // Un-choose (backtrack)
        }
    }
};