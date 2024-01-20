
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void printmazeplay(const vector<vector<int>>& array, int min, int max, int x, int y) {
    const int numRows = array.size();
    const int numCols = (numRows > 0) ? array[0].size() : 0;

    // ANSI escape codes for text color
    const char* greenText = "\033[1;32m";
    const char* redText = "\033[1;31m";
    const char* bluetext = "\033[34m";
    const char* resetText = "\033[0m";

    // Print the top border
    cout << "*";
    for (int j = 0; j < numCols; ++j) {
        cout << "-----*";
    }
    cout << endl;


    // Print the array with borders
    for (int i = 0; i < numRows; ++i) {
        cout << "|";
        for (int j = 0; j < numCols; ++j) {
            int currentValue = array[i][j];
            if (x == i && y == j) {
                cout << bluetext << setw(5) << currentValue << resetText << "|";
            }
            else if (i == numRows - 1 && j == numCols - 1) {
                // Bottom right corner: print in red
                cout << redText << setw(5) << currentValue << resetText << "|";
            }
            else {
                // Check if the value is less than -5
                if (currentValue < min && currentValue != 0) {


                    cout << greenText << setw(5) << currentValue + abs(max) * 2 + abs(min) * 2 + 1 << resetText << "|";
                }
                else {
                    // Otherwise, print normally
                    cout << setw(5) << currentValue << "|";
                }
            }
        }
        cout << endl;

        // Print the mid border
        cout << "*";
        for (int j = 0; j < numCols; ++j) {
            cout << "-----*";
        }
        cout << endl;
    };
}

bool isvalidmoveplay(vector<vector<int>>& maze, int x, int y, int minyy) {
    return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() &&
        (maze[x][y] != 0 && (maze[x][y] >= minyy || (maze[x][y] < minyy && x == maze.size() - 1 && y == maze[0].size() - 1)));
}

inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void newmap(vector<vector<int>> vec, int row, int col, int steps, string mapname);
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

const int SPECIAL_VALUE = std::numeric_limits<int>::max();

std::string get_localtime() {
    char buffer[80];
    time_t now = std::time(nullptr);

    struct tm localTime;
    localtime_s(&localTime, &now);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d-%H:%M:%S", &localTime);

    return std::string(buffer);
}


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


