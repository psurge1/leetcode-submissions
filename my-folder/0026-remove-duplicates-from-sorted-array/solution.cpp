class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        Input: integer array sorted in non-decreasing order
        Output: number of unique elements, also must remove duplicates from nums in-place


        [0, 0, 1, 2, 2, 2, 3, 4, 4]
        Approach: two pointers, one pointer for unique element insertion, another to iterate over the whole array
        */

        int arrLength = nums.size();
        int arrPtr = 0;
        int uniquePtr = 0;
        int prevVal = -101; // impossible value in nums
        while (arrPtr < arrLength) {
            if (nums[arrPtr] != prevVal) {
                nums[uniquePtr] = nums[arrPtr];
                prevVal = nums[arrPtr];
                ++uniquePtr;
            }
            ++arrPtr;
        }

        return uniquePtr;
    }
};
