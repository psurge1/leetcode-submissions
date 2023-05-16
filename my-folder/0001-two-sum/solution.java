class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] twos = new int[2];
        for (int i = 0; i < nums.length; ++i)
        {
            for (int k = i + 1; k < nums.length; ++k)
            {
                if (nums[i] + nums[k] == target)
                {
                    twos[0] = i;
                    twos[1] = k;
                }
            }
        }
        return twos;
    }
}
