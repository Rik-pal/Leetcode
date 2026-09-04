class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1};
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;          // Record position
                right = mid - 1;    // Keep searching left half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;          // Record position
                left = mid + 1;     // Keep searching right half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};