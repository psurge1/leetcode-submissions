class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        Inputs: nums-array of integers
        Output: array of triplet pairs that add to 0, where each triplet's index in nums is distinct
        - triplets don't have to be ordered/sorted
        Brute Force: O(n^3)-for each number, pair it with another distinct number, and iterate once more to find a number that adds to 0.
        - flaw: i=1,j=2,k=3 is treated seperately to i=3,j=1,k=2 (it is the same)
        - workaround: never repeat triplet pairs (j is bounded by i and n(size), k is bounded by j and n)
        - flaw: duplicate numbers with different indeces
        this approach still does redundant work

        Attempt:
        */

        vector<vector<int>> solution;

        // nlogn
        sort(nums.begin(), nums.end());
        
        // n^2
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int target = nums[i];
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int lPtr = i + 1;
            int rPtr = n - 1;
            while (lPtr < rPtr) {
                int shouldBeZero = target + nums[lPtr] + nums[rPtr];
                if (shouldBeZero == 0) {
                    solution.push_back(vector<int>{target, nums[lPtr], nums[rPtr]});
                    do {
                        --rPtr;
                    } while (lPtr < rPtr && nums[rPtr] == nums[rPtr + 1]);
                } else if (shouldBeZero < 0) {
                    ++lPtr;
                } else {
                    --rPtr;
                }
            }
        }

        return solution;
    }
};
