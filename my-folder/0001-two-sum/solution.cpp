class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, int> targets;
        for (int index = 0; index < nums.size(); ++index) {
            targets[target - nums[index]] = index;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (targets.contains(nums[index])) {
                if (index != targets[nums[index]]) {
                    solution.push_back(index);
                    solution.push_back(targets[nums[index]]);
                    return solution;
                }
            }
        }

        return solution;
    }
};
