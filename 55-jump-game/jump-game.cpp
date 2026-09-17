class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;   // farthest index we can reach so far

        for (int i = 0; i < nums.size(); i++) {
            // If we can't even reach the current index, we're stuck
            if (i > maxReach) 
                return false;
            
            // Update the farthest reachable index
            maxReach = max(maxReach, i + nums[i]);
            
            // Early exit: already can reach the end
            if (maxReach >= nums.size() - 1) 
                return true;
        }

        return true;
    }
};