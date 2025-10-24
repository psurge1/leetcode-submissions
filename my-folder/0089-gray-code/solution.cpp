class Solution {
public:
    vector<int> grayCode(int n) {
        int num_elements = pow(2, n);
        vector<int> solution(num_elements, 0);

        for (int num = 0; num < num_elements; ++num) {
            solution[num] = num ^ (num / 2);
        }

        return solution;
    }
};

/*
00 01 11 10
000 000
001 001
011 010
010 011
110 100
111 101
101 110
100 111
*/
