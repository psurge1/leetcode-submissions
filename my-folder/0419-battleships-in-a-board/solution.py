class Solution:
    def countBattleships(self, board: list[list[str]]) -> int:
        height = len(board)
        width = len(board[0])

        def sink_ship(row, col):
            d_row = [-1, 1, 0, 0]
            d_col = [0, 0, -1, 1]
            board[row][col] = "."
            for d in range(4):
                new_row = row + d_row[d]
                new_col = col + d_col[d]
                if new_row >= 0 and new_col >= 0 and new_row < height and new_col < width and board[new_row][new_col] == "X":
                    sink_ship(new_row, new_col)

        count = 0
        for row in range(height):
            for col in range(width):
                if board[row][col] == "X":
                    count += 1
                    sink_ship(row, col)
        return count
