class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_target = 0;
        bool closest_target_set = false;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int cur_sum = nums[i] + nums[j] + nums[k];
                if (closest_target_set) {
                    if (abs(target - cur_sum) < abs(target - closest_target)) {
                        closest_target = cur_sum;
                    }
                }
                else {
                    closest_target = cur_sum;
                    closest_target_set = true;
                }
                if (cur_sum > target) {
                    --k;
                }
                else if (cur_sum < target) {
                    ++j;
                }
                else {
                    break;
                }
            }
        }
        return closest_target;
    }
};
