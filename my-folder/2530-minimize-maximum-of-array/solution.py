class Solution:
    def minimizeArrayValue(self, nums: list[int]) -> int:
        max_prefix_avg = 0
        running_sum = 0
        for i in range(len(nums)):
            running_sum += nums[i]
            max_prefix_avg = max(max_prefix_avg, math.ceil(running_sum / (i + 1)))

        return max_prefix_avg
