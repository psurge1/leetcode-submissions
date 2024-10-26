class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> anagramIndeces;
        // for (int i = 0, n = strs.size(); i < n; ++i) {
        //     string word = strs[i];
        //     sort(word.begin(), word.end());
        //     anagramIndeces[word].push_back(strs[i]);
        // }

        // vector<vector<string>> result;
        // for (auto keyValue : anagramIndeces) {
        //     result.push_back(keyValue.second);
        // }
        // return result;

        unordered_map<string, vector<string>> anagramGroups;
        for (string& str : strs) { // O(N)
            vector<int> arr(26, 0);
            for (char c : str) { // O(M)
                arr[c - 'a']++;
            }
            string hash = "";
            for (int character = 'a'; character <= 'z'; ++character) {
                for (int i = 0; i < arr[character - 'a']; ++i) {
                    hash += character; // O(M)
                }
            }
            anagramGroups[hash].push_back(str); // O(M)
        }

        vector<vector<string>> result;
        for (auto keyValue : anagramGroups) {
            result.push_back(keyValue.second);
        }
        return result;
    }
};
