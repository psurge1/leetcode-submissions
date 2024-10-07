class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        int minLength = strs[0].length() < strs[strs.length - 1].length() ? strs[0].length() : strs[strs.length - 1].length();
        int index = 0;
        while ((index != minLength) && (strs[0].charAt(index) == strs[strs.length - 1].charAt(index))) {
            ++index;
        }
        return strs[0].substring(0, index);
    }
}
