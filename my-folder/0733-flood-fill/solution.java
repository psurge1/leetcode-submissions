class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        /*
        For every cell in a group of adjacent cells with the same color, change that value to the new color
        Adjacency means a horizontal or vertical neighbor
        Color is an integer

        Approach: DFS or BFS
        - DFS: recursion (more computationally expensive with the instruction stack)
        - BFS: stack
        */

        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;
        image[sr][sc] = color;

        // UP DOWN LEFT RIGHT
        int[] dX = {0, 0, -1, 1};
        int[] dY = {-1, 1, 0, 0};

        for (int direction = 0; direction < 4; ++direction) {
            int newX = sc + dX[direction];
            int newY = sr + dY[direction];
            if (newY >= 0 && newY < image.length && newX >= 0 && newX < image[newY].length) {
                if (image[newY][newX] == originalColor) {
                    floodFill(image, newY, newX, color);
                }
            }
        }
        return image;
    }
}
