class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numberCount;
        for (int num : nums) {
            ++numberCount[num];
        }
        priority_queue<pair<int, int>> heap;
        for (auto& numberCountPair : numberCount) {
            heap.push({numberCountPair.second, numberCountPair.first});
        }
        vector<int> answer;
        for (int i = 0; i < k; ++i) {
            answer.push_back(heap.top().second);
            heap.pop();
        }
        return answer;
    }
};
