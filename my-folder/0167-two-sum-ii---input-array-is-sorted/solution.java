class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int startPtr = 0;
        int endPtr = numbers.length - 1;
        while (startPtr < endPtr) {
            int ptrSum = numbers[startPtr] + numbers[endPtr];
            if (ptrSum < target) {
                ++startPtr;
            }
            else if (ptrSum > target) {
                --endPtr;
            }
            else {
                return new int[]{startPtr + 1, endPtr + 1};
            }
        }
        return new int[]{-1, -1};
    }
}
