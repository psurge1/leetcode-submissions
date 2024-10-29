class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabet[26];
        for (int i = 0; i < 26; ++i) {
            alphabet[i] = 0;
        }

        for (char k : s) {
            ++alphabet[k - 'a'];
        }

        for (char b : t) {
            --alphabet[b - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] != 0)
                return false;
        }
        return true;
    }
};

