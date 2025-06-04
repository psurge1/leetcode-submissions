class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numTracker = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int complement = target - nums[i];
            int complementIndex = numTracker.getOrDefault(complement, -1);
            if (complementIndex == -1)
                numTracker.put(nums[i], i);
            else
                return new int[]{complementIndex, i};
        }
        return new int[]{-1, -1};
    }
}
