class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int slow = 2;  // Position to write next valid element
        
        for (int fast = 2; fast < nums.size(); fast++) {
            // Compare with element 2 positions behind slow pointer
            // If different, we can add nums[fast] (appears ≤ 2 times so far)
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        
        return slow;
    }
};