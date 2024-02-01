class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> lset;
        int maxlength = 0;
        for (int i = 0, k, n = s.length(); i < n; ++i)
        {
            lset.clear();
            k = 0;
            for (int j = i; j < n; ++j)
            {
                if (lset.find(s[j]) == lset.end())
                {
                    lset.insert(s[j]);
                    ++k;
                }
                else
                {
                    maxlength = k > maxlength ? k : maxlength;
                    j = s.length();
                }
                if (j == n - 1)
                {
                    maxlength = k > maxlength ? k : maxlength;
                    j = s.length();
                }
            }
        }
        return maxlength;
    }
};
