class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow_ptr = 0;
        int fast_ptr = slow_ptr;

        do {
            slow_ptr = nums[slow_ptr];
            fast_ptr = nums[nums[fast_ptr]];
        } while (slow_ptr != fast_ptr);

        slow_ptr = 0;
        while (slow_ptr != fast_ptr) {
            slow_ptr = nums[slow_ptr];
            fast_ptr = nums[fast_ptr];
        }
        return slow_ptr;
    }
};
