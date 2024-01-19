class Solution {
public:
    string intToRoman(int num) {
        string romanCharacters[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int romanValues[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        int i = 12;
        string returnValue = "";
        while (num >= 0)
        {
            if (num == 0)
                return returnValue;
            if (romanValues[i] <= num)
            {
                returnValue += romanCharacters[i];
                num -= romanValues[i];
            }
            else
                --i;
        }
        return returnValue;
    }
};
