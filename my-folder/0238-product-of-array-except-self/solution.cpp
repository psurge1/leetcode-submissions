class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int numZeros = 0;
        for (int num : nums) {
            if (num == 0)
                ++numZeros;
            else
                product *= num;
        }

        vector<int> answer;
        for (int i = 0; i < nums.size(); ++i) {
            if (numZeros > 0) {
                if (numZeros > 1) {
                    answer.push_back(0);
                }
                else {
                    if (nums[i] == 0) {
                        answer.push_back(product);
                    }
                    else {
                        answer.push_back(0);
                    }
                }
            }
            else {
                answer.push_back(product / nums[i]);
            }
        }
        return answer;
    }
};
