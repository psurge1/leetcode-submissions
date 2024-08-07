class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet uniqueElements = new HashSet();
        for (int i = 0; i < nums.length; ++i)
        {
            if (uniqueElements.contains(nums[i]))
                return true;
            uniqueElements.add(nums[i]);
        }
        return false;
    }
}
