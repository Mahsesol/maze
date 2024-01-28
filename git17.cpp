
// function to solve any maze
bool mazesolution(vector<vector<int>>& maze, int x, int y, int destX, int destY, int steps, int min, int max, int sum, vector<vector<int>>& maze1) {

    // Base cases
    if (!isValid(x, y, maze.size(), maze[0].size())) {
        return false;
    }

    if (maze[x][y] < min && (x != destX && y != destY)) {
        return false;
    }
    if (maze[x][y] == 0) {
        return false;
    }

    if (steps < 0) {
        return false;
    }

    if (x == destX && y == destY && maze[x][y] == sum && steps == 0) {
        maze1 = maze;
        return true;
    }

    // Recursive backtracking
    sum += maze[x][y];
    int change = 2 * (abs(max) + abs(min)) + 1;
    maze[x][y] -= change;

    if (mazesolution(maze, x + 1, y, destX, destY, steps - 1, min, max, sum, maze1) || mazesolution(maze, x - 1, y, destX, destY, steps - 1, min, max, sum, maze1)
        || mazesolution(maze, x, y + 1, destX, destY, steps - 1, min, max, sum, maze1) || mazesolution(maze, x, y - 1, destX, destY, steps - 1, min, max, sum, maze1)) {
        return true;
    }


    // If no valid path found, backtrack
    maze[x][y] += change;
    sum -= maze[x][y];
    return false;
}
