class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        """
        keep track of a prefix sum
        also keep a hashmap of prefix sum values and their minimum index in the prefix sum array
        iterate negatively through the prefix sum, trying to identify two indeces with the same prefix sum value
        """

        n = len(nums)
        prefix_sums = [0] * (n + 1)
        ps_min_idx = dict()
        ps_min_idx[0] = 0
        for i in range(1, n + 1):
            addend = -1
            if nums[i - 1] == 1:
                addend = 1
            ps = prefix_sums[i - 1] + addend
            prefix_sums[i] = ps
            if ps not in ps_min_idx:
                ps_min_idx[ps] = i
        
        max_length = 0
        for i in range(n, -1, -1):
            if prefix_sums[i] in ps_min_idx:
                max_length = max(max_length, i - ps_min_idx[prefix_sums[i]])
        
        return max_length
