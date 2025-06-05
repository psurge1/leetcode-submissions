class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
        }
        else {
            // if no adjacent mines, change to B and recursively reveal all adjacent squares
            // if adjacent mine, change to number depicting amount of adjacent mines
            dfs(board, click[0], click[1]);
        }
        return board;
    }
    public void dfs(char[][] board, int row, int col) {
        int[] dRow = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
        int[] dCol = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
        board[row][col] = '.';

        int numBombs = 0;
        for (int i = 0; i < dRow.length; ++i) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow < 0 || newCol < 0 || newRow >= board.length || newCol >= board[newRow].length)
                continue;
            if (board[newRow][newCol] == 'M')
                ++numBombs;
        }
        if (numBombs == 0) {
            board[row][col] = 'B';
            for (int i = 0; i < dRow.length; ++i) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if (newRow < 0 || newCol < 0 || newRow >= board.length || newCol >= board[newRow].length)
                    continue;
                if (board[newRow][newCol] == 'E')
                    dfs(board, newRow, newCol);
            }
        }
        else
            board[row][col] = Character.forDigit(numBombs, 10);
    }
}
