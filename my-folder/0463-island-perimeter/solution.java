class Solution {
    public int islandPerimeter(int[][] grid) {
        for (int y = 0; y < grid.length; ++y) {
            for (int x = 0; x < grid[y].length; ++x) {
                if (grid[y][x] == 1) {
                    return dfs(grid, x, y);
                }
            }
        }
        // no island present
        return 0;
    }

    public int dfs(int[][] grid, int x, int y) {
        grid[y][x] = -1;
        int perimeter = 0;
        // Iterate over all edges, counting edges with water or border
        // UP DOWN LEFT RIGHT
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        for (int direction = 0; direction < 4; ++direction) {
            int neighborX = x + dx[direction];
            int neighborY = y + dy[direction];
            if (neighborY < 0 || neighborY >= grid.length || neighborX < 0 || neighborX >= grid[y].length) {
                ++perimeter;
            }
            else if (grid[neighborY][neighborX] == 0) {
                ++perimeter;
            }
            else if (grid[neighborY][neighborX] == 1) {
                perimeter += dfs(grid, neighborX, neighborY);
            }
        }
        return perimeter;
    }
}
