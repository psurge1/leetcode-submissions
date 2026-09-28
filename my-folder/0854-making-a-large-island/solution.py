class Solution:
    def largestIsland(self, grid: list[list[int]]) -> int:
        height = len(grid)
        width = len(grid[0])

        d_row = [-1, 1, 0, 0]
        d_col = [0, 0, -1, 1]

        island_id = 2
        max_island_size = 0
        island_size = defaultdict(int)

        def validate_coord(r, c):
            return r >= 0 and c >= 0 and r < height and c < width and grid[r][c] != 0
        
        def dfs(r, c):
            grid[r][c] = island_id
            island_size[island_id] += 1
            for d in range(4):
                new_r, new_c = r + d_row[d], c + d_col[d]
                if validate_coord(new_r, new_c) and grid[new_r][new_c] != island_id:
                    dfs(r + d_row[d], c + d_col[d])

        for row in range(height):
            for col in range(width):
                if grid[row][col] == 1:
                    dfs(row, col)
                    max_island_size = max(max_island_size, island_size[island_id])
                    island_id += 1
    
        for row in range(height):
            for col in range(width):
                if grid[row][col] == 0:
                    island_ids = set()
                    for d in range(4):
                        new_row = row + d_row[d]
                        new_col = col + d_col[d]
                        if validate_coord(new_row, new_col):
                            island_ids.add(grid[new_row][new_col])
                    new_island_size = 1
                    for iid in island_ids:
                        new_island_size += island_size[iid]
                    max_island_size = max(max_island_size, new_island_size)
        return max_island_size
