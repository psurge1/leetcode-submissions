class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;

        vector<char> vectorS;
        vector<char> vectorT;
        for (int i = 0; i < n; ++i) {
            vectorS.push_back(s[i]);
            vectorT.push_back(t[i]);
        }
        sort(vectorS.begin(), vectorS.end());
        sort(vectorT.begin(), vectorT.end());

        return vectorS == vectorT;
    }
};
