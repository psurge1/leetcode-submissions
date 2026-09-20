class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        """
        sliding window tracking sum
        both endpoints inclusive
        """

        n = len(nums)
        prefix_sum = 0
        existing_prefix_sums = dict()
        existing_prefix_sums[0] = 1
        count = 0
        for i in range(len(nums)):
            prefix_sum += nums[i]
            if prefix_sum - k in existing_prefix_sums:
                count += existing_prefix_sums[prefix_sum - k]
            if prefix_sum not in existing_prefix_sums:
                existing_prefix_sums[prefix_sum] = 0
            existing_prefix_sums[prefix_sum] += 1

        return count
