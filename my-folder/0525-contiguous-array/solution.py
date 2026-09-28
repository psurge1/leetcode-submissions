class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_sums = dict() # maps sums to indeces
        prefix_sums[0] = 0

        max_width = 0
        running_sum = 0
        for i in range(1, len(nums) + 1):
            running_sum += nums[i - 1] * 2 - 1
            if running_sum in prefix_sums:
                max_width = max(max_width, i - prefix_sums[running_sum])
            else:
                prefix_sums[running_sum] = i
        return max_width
