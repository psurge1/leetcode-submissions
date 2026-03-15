class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); ++i) {
            int h_ptr = i;
            int n_ptr = 0;
            while (n_ptr < needle.size()) {
                if (haystack[h_ptr] != needle[n_ptr]) {
                    break;
                }
                ++h_ptr;
                ++n_ptr;
            }
            if (n_ptr == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};
