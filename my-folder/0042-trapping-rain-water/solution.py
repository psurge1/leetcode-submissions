class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        left = 0
        right = n - 1
        left_max = height[left]
        right_max = height[right]
        water = 0
        while left < right:
            if height[left] <= height[right]:
                left += 1
                water += max(0, min(left_max, right_max) - height[left])
                left_max = max(left_max, height[left])
            else:
                right -= 1
                water += max(0, min(left_max, right_max) - height[right])
                right_max = max(right_max, height[right])
        return water
