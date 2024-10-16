class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = s.size() - 1;
        while (s[k] == ' ') {
            --k;
        }

        int i = k;
        for (; i >= 0; --i) {
            if (s[i] == ' ') {
                return k - i;
            }
        }
        return k - i;
    }
};
