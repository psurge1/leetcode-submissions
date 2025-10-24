class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        for (int i = 0, n = nums.size(); i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long cur_sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (cur_sum < target) {
                        ++k;
                    }
                    else if (cur_sum > target) {
                        --l;
                    }
                    else {
                        solution.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                    }
                }
                while (j < n - 2 && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i < n - 3 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return solution;
    }
};
