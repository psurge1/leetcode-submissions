class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int ptr1 = 0, ptr2 = 0;
        while ((ptr1 < nums1.size()) && (ptr2 < nums2.size())) {
            if (nums1[ptr1] < nums2[ptr2]) {
                nums.push_back(nums1[ptr1]);
                ++ptr1;
            }
            else {
                nums.push_back(nums2[ptr2]);
                ++ptr2;
            }
        }
        while (ptr1 < nums1.size()) {
            nums.push_back(nums1[ptr1]);
            ++ptr1;
        }
        while (ptr2 < nums2.size()) {
            nums.push_back(nums2[ptr2]);
            ++ptr2;
        }

        int size = nums.size();
        cout << size << endl;
        if (size % 2 == 0) {
            return (nums[size / 2] + nums[size / 2 - 1]) / 2.0;
        }
        else {
            return nums[size / 2];
        }
    }
};
