class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (height == 0)
            return;
        int width = board[0].size();

        for (int x = 0; x < width; ++x) {
            dfs(board, x, 0, width, height);
            dfs(board, x, height-1, width, height);
        }
        for (int y = 1; y < height-1; ++y) {
            dfs(board, 0, y, width, height);
            dfs(board, width-1, y, width, height);
        }

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (board[y][x] == 'O')
                    board[y][x] = 'X';
                if (board[y][x] == '.')
                    board[y][x] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y, int width, int height) {
        if (x < 0 || x >= width || y < 0 || y >= height || board[y][x] != 'O')
            return;
        board[y][x] = '.';
        
        array<int, 4> dX = {0, 0, -1, 1};
        array<int, 4> dY = {-1, 1, 0, 0};
        for (int d = 0; d < 4; ++d) {
            dfs(board, x + dX[d], y + dY[d], width, height);
        }
    }
};
