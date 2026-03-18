class Solution {
public:
    void process(
        const string& s, 
        int index, 
        const unordered_map<char, pair<int, int>>& umap, 
        vector<string>& result, 
        string& builder
        ) {
        if (index == s.size()) {
            result.push_back(builder);
        }
        else {
            char curr_char = s[index];
            for (int i = umap.at(curr_char).first; i <= umap.at(curr_char).second; ++i) {
                builder.push_back('a' + i);
                process(s, index + 1, umap, result, builder);
                builder.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string builder = "";
        unordered_map<char, pair<int, int>> umap = {
            {'2', {0, 2}},
            {'3', {3, 5}},
            {'4', {6, 8}},
            {'5', {9, 11}},
            {'6', {12, 14}},
            {'7', {15, 18}},
            {'8', {19, 21}},
            {'9', {22, 25}},
        };

        process(digits, 0, umap, result, builder);

        return result;
    }
};
