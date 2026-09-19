class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_indeces = dict()
        l = 0
        r = 0
        max_len = 0
        while r < len(s):
            if s[r] in char_indeces:
                dup_idx = char_indeces[s[r]]
                while l <= dup_idx:
                    char_indeces.pop(s[l])
                    l += 1
            char_indeces[s[r]] = r
            max_len = max(max_len, r - l + 1)
            r += 1
        return max_len
