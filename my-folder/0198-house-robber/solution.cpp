class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        vector<int> optTable(n, -1);
        optTable[0] = nums[0];

        return opt(n - 1, nums, optTable);
    }

    int opt(int n, const vector<int>& houses, vector<int>& optTable) {
        if (n < 0)
            return 0;
        if (optTable[n] != -1)
            return optTable[n];
        optTable[n] = max(
            houses[n] + opt(n - 2, houses, optTable),
            opt(n - 1, houses, optTable)
        );
        return optTable[n];
    }
};
