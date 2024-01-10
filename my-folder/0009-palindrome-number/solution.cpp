class Solution {
public:
    bool isPalindrome(int x) {
        std::string k = std::to_string(x);
        short w = k.length();
        short ptr1 = 0, ptr2 = w - 1;
        while (ptr1 != ptr2)
        {
            if (k[ptr1] != k[ptr2])
                return false;
            ++ptr1;
            if (ptr1 == ptr2)
                return true;
            --ptr2;
        }
        return true;
    }
};
