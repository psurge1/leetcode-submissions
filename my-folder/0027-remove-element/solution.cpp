class Solution {
public:
/*
    count = 0
    [0,1,2,2,3,0,4,2]
               |
           |
*/
    int removeElement(vector<int>& nums, int val) {
        int search_ptr = 0;
        int insert_ptr = 0;
        int n = nums.size();
        int count = 0;

        while (search_ptr < n) {
            if (nums[search_ptr] == val) {
                ++count;
            }
            else {
                nums[insert_ptr] = nums[search_ptr];
                ++insert_ptr;
            }
            ++search_ptr;
        }
        // nums.erase(nums.begin() + insert_ptr, nums.end());
        return n - count;
    }
};
