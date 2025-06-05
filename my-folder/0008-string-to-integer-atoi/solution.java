class Solution {
    public int myAtoi(String s) {
        int sign = 1;
        int i = 0;
        long result = 0;
        for (; i < s.length(); ++i) {
            if (s.charAt(i) != ' ')
                break;
        }
        if (i == s.length())
            return 0;
        if (s.charAt(i) == '-') {
            sign = -1;
            ++i;
        }
        else if (s.charAt(i) == '+') {
            ++i;
        }
        while (i < s.length()) {
            char digit = s.charAt(i);
            if (!Character.isDigit(digit))
                break;
            result = result * 10 + (digit - '0');
            if (sign * result > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (sign * result < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            ++i;
        }
        return (int) (sign * result);
    }
}
