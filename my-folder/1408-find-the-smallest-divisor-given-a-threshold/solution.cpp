class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 0;
        for (const int num : nums) {
            high = max(high, num);
        }

        int smallest_divisor = 1;
        while (low <= high) {
            int divisor = (low + high) / 2;
            int divisor_sum = 0;
            for (const int num : nums) {
                divisor_sum += ceil(1.0 * num / divisor);
            }

            if (divisor_sum <= threshold) {
                high = divisor - 1;
                smallest_divisor = divisor;
            }
            else {
                low = divisor + 1;
            }
        }
        return smallest_divisor;
    }
};
