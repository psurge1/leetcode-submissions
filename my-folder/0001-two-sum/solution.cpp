class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, int> potential_targets;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            potential_targets.insert({target - nums[i], i});
            if (potential_targets.contains(nums[i]))
            {
                int other = potential_targets[nums[i]];
                if (i != other)
                {
                    solution = {i, other};
                    return solution;
                }
            }
        }
        return solution;
    }
};
