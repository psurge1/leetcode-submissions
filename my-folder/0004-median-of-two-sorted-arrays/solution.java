class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int k = nums1.length + nums2.length;
        int[] nums3 = new int[k];
        for (int i = 0; i < nums1.length; ++i)
        {
            nums3[i] = nums1[i];
        }
        for (int i = 0; i < nums2.length; ++i)
        {
            nums3[i + nums1.length] = nums2[i];
        }
        Arrays.sort(nums3);
        if (nums3.length % 2 != 0)
        {
            return nums3[k / 2];
        }
        else
        {
            return (nums3[k / 2] + nums3[(k / 2) - 1]) / 2.0;
        }
    }
}
