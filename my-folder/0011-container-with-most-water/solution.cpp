class Solution {
public:
    int maxArea(vector<int>& height) {
        int l_ptr = 0;
        int r_ptr = height.size() - 1;

        int max_water = 0;
        while (l_ptr < r_ptr) {
            max_water = max(max_water, min(height[l_ptr], height[r_ptr]) * (r_ptr - l_ptr));
            if (height[l_ptr] < height[r_ptr]) {
                ++l_ptr;
            }
            else {
                --r_ptr;
            }
        }
        return max_water;
    }
};
