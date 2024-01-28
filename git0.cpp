
//function to check if the input chioce is a number (valid)
bool check_number(string str) {
    if (str[0] == '-') {
        for (int i = 1; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    }
    else {
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    }
}


// functions to replace space with underline in user name and map name
// first one is windowa version and the commented one is mac version
string space_to_underline(string str) {
    size_t n = 0;
    while ((n = str.find(" ", n)) != string::npos) {
        str.replace(n, 1, "_");
        ++n;
    }
    return str;
}


// string space_to_underline(string str) {
//    int n;
 //   while (n != -1) {
//        n = str.find(" ");
//        if (n != -1) {
 //           str.replace(n, 1, "_");
 //       }
//    }

 //   return str;
//}



//function that add any new map made with program in the maps list in playground
void newmap(vector<vector<int>> vec, int row, int col, int steps, string mapname) {
    mapname = mapname + ".txt";
    ofstream file(mapname);
    file << row << " " << col << '\n' << steps << '\n';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            file << vec[i][j] << " ";
        }
        file << '\n';
    }
    ofstream mapsfile("maps.txt", ios::app);
    mapsfile << "\n" << mapname;
}



// functions thats been used in maze making functions (check rules to fill the maze)
const int SPECIAL_VALUE = std::numeric_limits<int>::max();

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// create the main path in hard maze maker
bool way(vector<vector<int>>& maze, int x, int y, int destX, int destY, int steps) {
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
    int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    srand(time(0));

    for (int i = 0; i < 4; ++i) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        swap(directions[i], directions[j]);

        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (way(maze, newX, newY, destX, destY, steps - 1)) {
            return true;
        }
    }

    // If no valid path found, backtrack
    maze[x][y] = SPECIAL_VALUE;
    return false;
}



// creating 0 blocks of maze
void blockmaker(vector<vector<int>>& matrix, int n) {
    int count = 0;
    srand(std::time(0));

    while (count < n) {
        size_t i = rand() % matrix.size();
        size_t j = rand() % matrix[i].size();

        if (matrix[i][j] == SPECIAL_VALUE) {
            matrix[i][j] = 0;
            ++count;
        }
    }
}



//function to check if there is stiil any way for user to move in play mode
bool isvalidmoveplay(vector<vector<int>>& maze, int x, int y, int minyy) {
    return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() &&
        (maze[x][y] != 0 && (maze[x][y] >= minyy || (maze[x][y] < minyy && x == maze.size() - 1 && y == maze[0].size() - 1)));
}



//functions that gets the time(now) and put it in a string format
//first one is windows vwersion and the commented one is the mac version
std::string get_localtime() {
    char buffer[80];
    time_t now = std::time(nullptr);

    struct tm localTime;
    localtime_s(&localTime, &now);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d-%H:%M:%S", &localTime);

    return std::string(buffer);
}



//string get_localtime() {
//    char buffer[80];
//    time_t now = std::time(nullptr);
//    strftime(buffer, 80, "%Y-%m-%d-%H:%M:%S", localtime(&now));
//    string result(buffer);
//    return result;
//}



// struct to save time
struct time {
    int minutes;
    int seconds;
};



