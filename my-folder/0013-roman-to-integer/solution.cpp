class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNumerals;
        romanNumerals['I'] = 1;
        romanNumerals['V'] = 5;
        romanNumerals['X'] = 10;
        romanNumerals['L'] = 50;
        romanNumerals['C'] = 100;
        romanNumerals['D'] = 500;
        romanNumerals['M'] = 1000;

        int previousValue = 0, currentValue, sumValue = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            currentValue = romanNumerals[s[i]];
            if (currentValue < previousValue)
                sumValue -= currentValue;
            else
                sumValue += currentValue;
            previousValue = currentValue;
        }
        return sumValue;
    }
};
