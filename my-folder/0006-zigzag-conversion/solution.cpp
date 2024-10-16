class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> rows(numRows);
        for (int i = 0; i < numRows; ++i) {
            rows.emplace_back();
        }

        int sSize = s.size();
        int ctr = 0;
        bool rising = false;
        for (int i = 0; i < sSize; ++i) {
            rows[ctr].push_back(s[i]);
            if (!rising) {
                ++ctr;
                if (ctr == numRows - 1) {
                    rising = true;
                }
            }
            else  {
                --ctr;
                if (ctr == 0)
                    rising = false;
            }
        }

        string returnS = "";
        for (const vector<char>& row : rows) {
            for (char k : row) {
                returnS += k;
            }
        }
        return returnS;
    }
};
