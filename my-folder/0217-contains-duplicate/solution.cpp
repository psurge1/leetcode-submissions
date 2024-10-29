class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> numbers;
        for (int num : nums) {
            if (numbers.contains(num)) {
                return true;
            }
            numbers.insert(num);
        }
        return false;
    }
};
