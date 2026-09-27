class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
    
private:
    void backtrack(int start, vector<int>& nums, 
                   vector<int>& current, vector<vector<int>>& result) {
        // KEY: Every node in the recursion tree is a valid subset
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);       // Choose nums[i]
            backtrack(i + 1, nums, current, result);  // Explore
            current.pop_back();               // Un-choose
        }
    }
};