class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        if (pricesSize <= 1) {
            return 0;
        }
        int startPtr = 0;
        int maxProfit = 0;
        for (int endPtr = 1; endPtr < pricesSize; ++endPtr) {
            if (prices[startPtr] >= prices[endPtr]) {
                startPtr = endPtr;
            }
            else if (prices[endPtr] - prices[startPtr] > maxProfit) {
                maxProfit = prices[endPtr] - prices[startPtr];
            }
        }

        return maxProfit;
    }
};
