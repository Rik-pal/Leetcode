class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        // Sorting is optional but helps with pruning and consistent output
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, int sum,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: exact match found
        if (sum == target) {
            result.push_back(current);
            return;
        }
        // Prune: sum exceeded target (only valid because we sorted)
        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Early termination: since sorted, all further numbers are larger
            if (sum + candidates[i] > target) break;

            current.push_back(candidates[i]);
            // Pass 'i' (not i+1) because we can reuse the same element
            backtrack(candidates, target, i, sum + candidates[i], current, result);
            current.pop_back();  // Backtrack
        }
    }
};