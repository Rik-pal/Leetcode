class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    if (sum == target) {

                        result.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // Skip duplicate left values
                        while (left < right &&
                               nums[left] == nums[left + 1]) {
                            left++;
                        }

                        // Skip duplicate right values
                        while (left < right &&
                               nums[right] == nums[right - 1]) {
                            right--;
                        }

                        left++;
                        right--;

                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};