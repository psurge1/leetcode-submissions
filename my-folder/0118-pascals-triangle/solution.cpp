class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.emplace_back();
        result[0].push_back(1);
        if (numRows == 1)
            return result;
        result.emplace_back();
        result[1].push_back(1);
        result[1].push_back(1);
        if (numRows == 2)
            return result;

        for (int i = 2; i < numRows; ++i) {
            result.emplace_back();
            result[i].push_back(1);
            for (int k = 0; k < i - 1; ++k) {
                result[i].push_back(result[i - 1][k] + result[i - 1][k + 1]);
            }
            result[i].push_back(1);
        }

        return result; 
    }
};
