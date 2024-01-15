bool generatePath(vector<vector<int>>& maze, int x, int y, int destX, int destY, int steps) {
    // Base cases
    if (!isValid(x, y, maze.size(), maze[0].size())) {
        return false;
    }

    if (maze[x][y] == 0 || maze[destX][destY] == 0) {
        return false;
    }

    if (steps < 0) {
        return false;
    }

    if (x == destX && y == destY && steps == 0) {
        maze[x][y] = 0;
        return true;
    }

    // Recursive backtracking
    maze[x][y] = 0;

    // Try moving in all four directions
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    srand(time(0));

    for (int i = 0; i < 4; ++i) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        swap(directions[i], directions[j]);

        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (generatePath(maze, newX, newY, destX, destY, steps - 1)) {
            return true;
        }
    }

    // If no valid path found, backtrack
    maze[x][y] = SPECIAL_VALUE;
    return false;
}