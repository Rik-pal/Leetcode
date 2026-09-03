class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find pivot — first index from right where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        
        // Step 2: If pivot exists, find the rightmost successor to swap with
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the suffix to get the smallest ordering
        reverse(nums.begin() + i + 1, nums.end());
    }
};