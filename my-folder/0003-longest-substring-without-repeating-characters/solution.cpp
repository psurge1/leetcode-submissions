class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringSize = s.size();
        if (stringSize < 2) {
            return stringSize;
        }

        int maxLength = 1;
        int leftPtr = 0;
        int rightPtr = 1;
        int indexOfCharacters[95]; // hash function: character - 32
        for (int arrIndex = 0; arrIndex < 95; ++arrIndex) {
            indexOfCharacters[arrIndex] = -1;
        }

        indexOfCharacters[s[leftPtr] - 32] = 0;
        while (rightPtr < stringSize) {
            char currentChar = s[rightPtr];
            if (indexOfCharacters[currentChar - 32] == -1) {
                indexOfCharacters[currentChar - 32] = rightPtr;
                ++rightPtr;
                maxLength = rightPtr - leftPtr > maxLength ? rightPtr - leftPtr : maxLength;
            }
            else {
                int temp = leftPtr;
                leftPtr = indexOfCharacters[currentChar - 32] + 1;
                for (temp; temp < leftPtr; ++temp) {
                    indexOfCharacters[s[temp] - 32] = -1;
                }
                indexOfCharacters[currentChar - 32] = rightPtr;
                ++rightPtr;
            }
        }

        return maxLength;
    }
};
