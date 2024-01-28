#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <cmath>
#include <chrono>
#include <thread>
#include <limits>
#include <fstream>
#include <ctime>
#include <chrono>
#include <cstdlib>
//#include <curses.h>
#include <conio.h>



using namespace std;
using namespace std::chrono;

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




//functions to find the max and min element in a 2D vector (for solving and playing user uploaded maze)
int minelement(vector<vector<int>> matrix) {
    int min = std::numeric_limits<int>::max();

    for_each(matrix.begin(), matrix.end(),
        [&min](const auto& v)
        {
            min = std::min(*min_element(v.begin(), v.end()), min);
        }
    );
    return min;
}


int maxelement(vector<vector<int>> matrix) {
    int max = std::numeric_limits<int>::min();

    for_each(matrix.begin(), matrix.end(),
        [&max](const auto& v)
        {
            max = std::max(*max_element(v.begin(), v.end()), max);
        }
    );
    return max;
}



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



// maze maker easy version
vector<vector<int>> easymazemaker() {
    random_device rd;
    mt19937 g(rd());
    string mapname;
    cout << "Enter your map name: ";
    cin.ignore(1, '\n');
    getline(cin, mapname);
    mapname = space_to_underline(mapname);
    cout << endl;
    string checkrow, checkcol;
    int row, col;
    cout << "Enter the size of your maze" << endl << "rows: ";
    try {
        cin >> checkrow;
        if (check_number(checkrow) == 0 || stoi(checkrow) <= 1) {
            throw checkrow;
        }
    }
    catch (...) {
        while (check_number(checkrow) == 0 || stoi(checkrow) <= 1) {
            cout << "Please enter the number of rows correctly" << endl << "The number of rows must be a digit greater than 1" << endl << "rows: ";
            cin >> checkrow;
        }
    }
    row = stoi(checkrow);
    cout << "columns:";
    try {
        cin >> checkcol;
        if (check_number(checkcol) == 0 || stoi(checkcol) <= 1) {
            throw checkcol;
        }
    }
    catch (...) {
        while (check_number(checkcol) == 0 || stoi(checkcol) <= 1) {
            cout << "Please enter the number of columns correctly" << endl << "The number of columns must be a digit greater than 1" << endl << "columns: ";
            cin >> checkcol;
        }
    }

    col = stoi(checkcol);
    int sum = 0;

    //sakht va por e maze
    vector<vector<int>> maze(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = SPECIAL_VALUE;
        }
    }

    vector<int> tartib;
    uniform_int_distribution<int> distribution(-3, 3);
    uniform_int_distribution<int> distribution2(2, 5);
    //vector tartib ke tartib ghadam haye ma ra moshkhas mikond ra por mikonim

    for (int i = 0; i < col - 1; i++) { tartib.push_back(1); }
    for (int i = 0; i < row - 1; i++) { tartib.push_back(0); }
    int y = 0;
    int x = 0;
    int val = 0;

    shuffle(tartib.begin(), tartib.end(), g);
    //bade taghir tartib ghadam ha masir ro por mikonim

    for (int i = 0; i < tartib.size(); i++) {
        val = distribution(g);
        while (val == 0) {
            val = distribution(g);
        }

        maze[y][x] = val;
        sum += val;

        while (sum == 0 && i == tartib.size() - 2) {
            sum -= val;
            val = distribution(g);
            while (val == 0) {
                val = distribution(g);
            }
            maze[y][x] = val;
            sum += val;
        }

        if (tartib[i] == 1) { x++; }
        else if (tartib[i] == 0) { y++; }
    }

    maze[row - 1][col - 1] = sum;
    blockmaker(maze, distribution2(g));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == SPECIAL_VALUE) {
                val = distribution(g);
                while (val == 0) {
                    val = distribution(g);
                }
                maze[i][j] = val;
            }
        }
    }


    newmap(maze, row, col, row + col - 2, mapname);

    return maze;
}




// maze maker hard version
vector<vector<int>> hardmazemaker() {
    random_device rd;
    mt19937 g(rd());

    string mapname;
    cout << endl << "Enter your mapname: ";
    cin.ignore(1, '\n');
    getline(cin, mapname);
    mapname = space_to_underline(mapname);
    cout << endl;

    string checkrow, checkcol;
    int row, col;
    cout << "Enter the size of your maze: " << endl << "rows: ";
    try {
        cin >> checkrow;
        if (check_number(checkrow) == 0 || stoi(checkrow) <= 1) {
            throw checkrow;
        }
    }
    catch (...) {
        while (check_number(checkrow) == 0 || stoi(checkrow) <= 1) {
            cout << "Please enter the number of rows correctly" << endl << "The number of rows must be a digit greater than 1" << endl << "rows: ";
            cin >> checkrow;
        }
    }
    row = stoi(checkrow);
    cout << "columns:";
    try {
        cin >> checkcol;
        if (check_number(checkcol) == 0 || stoi(checkcol) <= 1) {
            throw checkcol;
        }
    }
    catch (...) {
        while (check_number(checkcol) == 0 || stoi(checkcol) <= 1) {
            cout << "Please enter the number of columns correctly" << endl << "The number of columns must be a digit greater than 1" << endl << "columns: ";
            cin >> checkcol;
        }
    }
    col = stoi(checkcol);

    int sum = 0;
    string checkmin, checkmax;
    int min, max;
    cout << "Enter the minimum and maximum of your maze" << endl << "min: ";
    try {
        cin >> checkmin;
        if (check_number(checkmin) == 0) {
            throw checkmin;
        }
    }
    catch (...) {
        while (check_number(checkmin) == 0) {
            cout << "The minimum of your maze should be a number" << endl << "min: ";
            cin >> checkmin;
        }
    }
    min = stoi(checkmin);

    cout << "max:";
    try {
        cin >> checkmax;
        if (check_number(checkmax) == 0) {
            throw checkmax;
        }
    }
    catch (...) {
        while (check_number(checkmax) == 0) {
            cout << "The maximum of your maze should be a number" << endl << "max: ";
            cin >> max;
        }
    }
    max = stoi(checkmax);




    vector<vector<int>> maze(row, vector<int>(col));




    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = SPECIAL_VALUE;
        }
    }

    string checksteps;
    int step;

    cout << "Enter the steps of your path: ";
    try {
        cin >> checksteps;
        if (check_number(checksteps) == 0 || stoi(checksteps) < 0) {
            throw checkmin;
        }
    }
    catch (...) {
        while (check_number(checksteps) == 0 || stoi(checksteps) < 0) {
            cout << "Steps of you path should be a posetive number" << endl << "steps: ";
            cin >> checksteps;
        }
    }
    step = stoi(checksteps);

    if (!way(maze, 0, 0, row - 1, col - 1, step)) {
        cout << "There is no path with this number of steps. " << endl;
        while (!way(maze, 0, 0, row - 1, col - 1, step)) {
            cout << "Try agin :) " << endl << "Enter the steps of your path here: ";
            try {
                cin >> checksteps;
                if (check_number(checksteps) == 0 || stoi(checksteps) < 0) {
                    throw checkmin;
                }
            }
            catch (...) {
                while (check_number(checksteps) == 0 || stoi(checksteps) < 0) {
                    cout << "Steps of you path should be a posetive number" << endl << "steps: ";
                    cin >> checksteps;
                }
            }
            step = stoi(checksteps);
        }

    }



    string checkbmin, checkbmax;
    int blockmin, blockmax;
    cout << "Enter the minimum and maximum number of the blocks in your maze" << endl << "minimum number of blocks: ";
    try {
        cin >> checkbmin;
        if (check_number(checkbmin) == 0 || stoi(checkbmin) < 0) {
            throw checkbmin;
        }
    }
    catch (...) {
        while (check_number(checkbmin) == 0 || stoi(checkbmin) < 0) {
            cout << "The minimum number of blocks must be a posetive number" << endl << "minimum number of blocks: ";
            cin >> checkbmin;
        }
    }
    blockmin = stoi(checkbmin);

    cout << "maximum number of blocks:";
    try {
        cin >> checkbmax;
        if (check_number(checkbmax) == 0 || stoi(checkbmax) < blockmin || stoi(checkbmax) > row * col - step) {
            throw checkbmax;
        }
    }
    catch (...) {
        if (check_number(checkbmax) == 0 || stoi(checkbmax) < blockmin) {
            while (check_number(checkbmax) == 0 || stoi(checkbmax) < min) {
                cout << "The maximum number of blocks must be a posetive number greater than minimum number of blocks" << endl << "maximum number of blocks: ";
                cin >> checkbmax;
            }
        }
        else {
            while (stoi(checkbmax) > row * col - step) {
                cout << "Too many blocks for your path!" << endl << "maximum number of blocks: ";
                cin >> checkbmax;
            }
        }
    }
    blockmax = stoi(checkbmax);





    uniform_int_distribution<int> distribution(min, max);
    uniform_int_distribution<int> distribution1(blockmin, blockmax);
    sum = 0;

    int val = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == row - 1 && j == col - 1) {
                break;
            }
            if (maze[i][j] == 0) {
                val = distribution(g);
                while (val == 0) {
                    val = distribution(g);
                }
                maze[i][j] = val;
                sum += val;
                while (((i == row - 2 && j == col - 2) || (i == row - 1 && j == row - 2) || (j == col - 1 && i == row - 2)) && sum == 0) {
                    sum -= val;
                    val = distribution(g);
                    while (val == 0) {
                        val = distribution(g);
                    }
                    maze[i][j] = val;
                    sum += val;

                }

            }


        }
    }

    maze[row - 1][col - 1] = 0;
    blockmaker(maze, distribution1(g));
    maze[row - 1][col - 1] = sum;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == SPECIAL_VALUE && ((i != row - 1) || (j != col - 1))) {
                val = distribution(g);
                while (val == 0) {
                    val = distribution(g);
                }
                maze[i][j] = val;
            }


        }


    }
    newmap(maze, row, col, step, mapname);
    return maze;
}


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



//function to print mazes
void printmaze(const vector<vector<int>>& array, int min, int max) {
    const int numRows = array.size();
    const int numCols = (numRows > 0) ? array[0].size() : 0;

    // ANSI escape codes for text color
    const char* greenText = "\033[1;32m";
    const char* redText = "\033[1;31m";
    const char* yellowText = "\033[1;33m";
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
            if (currentValue == 0) {
                cout << yellowText << setw(5) << currentValue << resetText << "|";
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


//function to check if there is stiil any way for user to move in play mode
bool isvalidmoveplay(vector<vector<int>>& maze, int x, int y, int minyy) {
    return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() &&
        (maze[x][y] != 0 && (maze[x][y] >= minyy || (maze[x][y] < minyy && x == maze.size() - 1 && y == maze[0].size() - 1)));
}


//function to print maze in play mode
void printmazeplay(const vector<vector<int>>& array, int min, int max, int x, int y) {
    const int numRows = array.size();
    const int numCols = (numRows > 0) ? array[0].size() : 0;

    // ANSI escape codes for text color
    const char* greenText = "\033[1;32m";
    const char* redText = "\033[1;31m";
    const char* bluetext = "\033[34m";
    const char* yellowText = "\033[1;33m";
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
            if (currentValue == 0) {
                cout << yellowText << setw(5) << currentValue << resetText << "|";
            }
            else if (x == i && y == j) {
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



//the main game function
int play(vector<vector<int>> maze, int min, int max, int& steps) {
    char play;
    int sum = 0;
    int x = 0, y = 0;
    int adjustment = 2 * (abs(min) + abs(max)) + 1;
    //x va y bar aksand :)
    cout << "start playing:" << endl;
    cout << "press w to go up" << endl;
    cout << "press s to go down" << endl;
    cout << "press a to go left" << endl;
    cout << "press d to go right" << endl;


    printmazeplay(maze, min, max, 0, 0);

    while (steps > 0 && !(x == maze.size() - 1 && y == maze[0].size() - 1) && (isvalidmoveplay(maze, x - 1, y, min)
        || isvalidmoveplay(maze, x + 1, y, min) || isvalidmoveplay(maze, x, y - 1, min) || isvalidmoveplay(maze, x, y + 1, min))) {

        char play = _getch();
        //cin >> play;
        if (play == 'a' || play == 'A') {
            y--;
            if (isvalidmoveplay(maze, x, y, min)) {
                y++;
                sum += maze[x][y];
                maze[x][y] -= adjustment;
                y--;
                steps--;

                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }
            else {
                y++;
                cout << "you cant go there" << endl;
                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }

        }
        else if (play == 'd' || play == 'D') {
            y++;
            if (isvalidmoveplay(maze, x, y, min)) {
                y--;
                sum += maze[x][y];
                maze[x][y] -= adjustment;
                y++;
                steps--;

                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }
            else {
                y--;
                cout << "you cant go there" << endl;
                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }

        }
        else if (play == 's' || play == 'S') {
            x++;
            if (isvalidmoveplay(maze, x, y, min)) {
                x--;
                sum += maze[x][y];
                maze[x][y] -= adjustment;
                x++;
                steps--;

                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }
            else {
                x--;
                cout << "you cant go there" << endl;
                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }

        }
        else if (play == 'w' || play == 'W') {
            x--;
            if (isvalidmoveplay(maze, x, y, min)) {
                x++;
                sum += maze[x][y];
                maze[x][y] -= adjustment;
                x--;
                steps--;
                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }
            else {
                x++;
                cout << "you cant go there" << endl;
                printmazeplay(maze, min, max, x, y);
                cout << "steps left:" << steps << endl;
                cout << "sum:" << sum << endl;
            }
        }

        else {
            cout << "Do you want to fly? =) " << endl;
            cout << "Restart playing: " << endl;
            cout << "press w to go up" << endl;
            cout << "press s to go down" << endl;
            cout << "press a to go left" << endl;
            cout << "press d to go right" << endl;
        }

    }

    if (steps == 0 && x == maze.size() - 1 && y == maze[0].size() - 1 && maze[x][y] == sum) {
        cout << "\u001b[32;1m---* CONGRATULATIONS YOU WON *---\u001b[0m" << endl;
        return 1;
    }
    else {
        cout << " \u001b[31m---* OH NO YOU LOST! *---\u001b[0m" << endl;
        return 0;
    }
}


//function that allows user to choos from existing maps in maps list
string choosmap() {
    string str;
    ifstream file("maps.txt");
    vector<string> vec;
    while (getline(file, str)) {
        if (!str.empty()) {
            vec.push_back(str);
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << i + 1 << "." << vec[i] << endl;
    }
    string choice;
    cout << "enter your choice: ";
    cin >> choice;
    string mapname;
    if (check_number(choice) == 0 || stoi(choice) < 1 || stoi(choice) > vec.size()) {
        while (check_number(choice) == 0 || stoi(choice) < 1 || stoi(choice) > vec.size()) {
            cout << endl << "invalid choice" << endl << "enter yoru choice:";
            cin >> choice;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (i + 1 == stoi(choice)) {
            mapname = vec[i];
            break;
        }
    }

    return mapname;
}


//function that checks if a file exists or not
inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}



//function that turn user file into a maze (for solving or playing)
vector<vector<int>> userfiletovec(string& mapname) {
    vector<vector<int>> vec;
    string checktxt;
    if(mapname.size() > 4){
        checktxt = mapname.substr(mapname.size() - 4, 4);
        if (checktxt != ".txt") {
            mapname = mapname + ".txt";
        }
    }else{
            mapname = mapname + ".txt";
        }
    int exists = exists_test(mapname);
    if (exists == 0) {
        cout << "file does not exist!";
        while (exists == 0) {
            cout << "enter the name of your file correctly or enter '>' to exit: ";
            cin >> mapname;
            if (mapname == ">") {
                vec.push_back({ 0 });
                return vec;
            }
            else {
                if(mapname.size() > 4){
                    checktxt = mapname.substr(mapname.size() - 4, 4);
                    if (checktxt != ".txt") {
                        mapname = mapname + ".txt";
                    }
                }else{
                        mapname = mapname + ".txt";
                    }
                
                exists = exists_test(mapname);
            }
        }
    }
    ifstream file(mapname);
    string row, col;
    string steps;
    file >> row >> col >> steps;
    int row1 = stoi(row);
    int col1 = stoi(col);
    string** arr = new string * [row1];
    for (int i = 0; i < row1; i++) {
        arr[i] = new string[col1];
    }
    for (int i = 0; i < stoi(row); i++) {
        for (int j = 0; j < stoi(col); j++) {
            file >> arr[i][j];
        }
    }
    for (int i = 0; i < stoi(row); i++) {
        vec.push_back(vector<int>());
        for (int j = 0; j < stoi(col); j++) {
            int temp = stoi(arr[i][j]);
            vec[i].push_back(temp);
        }
    }
    mapname.erase(mapname.size() - 4, 4);
    return vec;
}



//function that turn existing map files in maps list into a maze(for solving or playing)
vector<vector<int>> filetovec(string mapname) {
    string checktxt = mapname.substr(mapname.size() - 4, 4);
    if (checktxt != ".txt") {
        mapname = mapname + ".txt";
    }
    ifstream file(mapname);
    string row, col;
    string steps;
    file >> row >> col >> steps;
    int row1 = stoi(row);
    int col1 = stoi(col);
    string** arr = new string * [row1];
    for (int i = 0; i < row1; i++) {
        arr[i] = new string[col1];
    }
    vector<vector<int>> vec;
    for (int i = 0; i < stoi(row); i++) {
        for (int j = 0; j < stoi(col); j++) {
            file >> arr[i][j];
        }
    }
    for (int i = 0; i < stoi(row); i++) {
        vec.push_back(vector<int>());
        for (int j = 0; j < stoi(col); j++) {
            vec[i].push_back(stoi(arr[i][j]));
        }
    }
    return vec;
}




// get the steps of path of maze frome the maze file (for solving or playing)
int getstepsfromfile(string mapname) {
    string checktxt = mapname.substr(mapname.size() - 4, 4);
    if (checktxt != ".txt") {
        mapname = mapname + ".txt";
    }
    ifstream file(mapname);
    string row, col;
    string steps;
    file >> row >> col >> steps;
    int steps1 = stoi(steps);
    return steps1;
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


//struct to save user information
struct userinfo {
    string name;
    int playcount;
    int wincount;
    string lastwin;
    int playingtime;
    int winplayingtime;
};


//function to get user information from file and save into a vector
userinfo getuserinfo(string name) {
    ifstream usernamesfile("username.txt");
    vector<string> usernames;
    string str;
    int check = 0;
    while (getline(usernamesfile, str)) {
        if (!str.empty()) {
            usernames.push_back(str);
            if (str == name) {
                check++;
                break;
            }
        }
    }
    userinfo user;
    if (check == 1) {
        name = name + ".txt";
        ifstream userfile(name);
        string playcount, wincount, playingtime, winplayingtime;
        getline(userfile, user.name);
        getline(userfile, playcount);
        getline(userfile, wincount);
        getline(userfile, user.lastwin);
        getline(userfile, playingtime);
        getline(userfile, winplayingtime);
        user.playcount = stoi(playcount);
        user.wincount = stoi(wincount);
        user.playingtime = stoi(playingtime);
        user.winplayingtime = stoi(winplayingtime);
        userfile.close();
    }
    else {
        user.name = name;
        user.playcount = 0;
        user.wincount = 0;
        user.lastwin = "never";
        user.playingtime = 0;
        user.winplayingtime = 0;
        ofstream usersfile("username.txt", ios::app);
        usersfile << "\n" << user.name;
        name = name + ".txt";
        ofstream thisuserfile(name);
        thisuserfile << user.name << "\n" << user.playcount << "\n" << user.wincount << "\n" << user.lastwin << "\n" << user.playingtime << "\n" << user.winplayingtime << "\n";

    }
    return user;
}




//function to update user information after playing a game and save it into file
void updateuserinfo(userinfo user, int gameresult, int playingtime) {
    user.playcount++;
    user.playingtime += playingtime;
    if (gameresult == 1) {
        user.wincount++;
        user.lastwin = get_localtime();
        user.winplayingtime += playingtime;
    }
    string name = user.name + ".txt";
    ofstream userfile(name);
    userfile << user.name << "\n" << user.playcount << "\n" << user.wincount << "\n" << user.lastwin << "\n" << user.playingtime << "\n" << user.winplayingtime << "\n";
}


//function to print user information
void printuserinfo(userinfo user) {
    //  cout << "\u001b[36m******** YOUR INFORMATION ********" << endl;
    struct time playtime;
    playtime.minutes = user.playingtime / 60;
    playtime.seconds = user.playingtime % 60;
    cout << endl << "\u001b[36;1mName: " << "\u001b[0m " << user.name << endl << "\u001b[36;1mPlay count: " << "\u001b[0m " << user.playcount << endl << "\u001b[36;1mWin count: " << "\u001b[0m " << user.wincount << endl << "\u001b[36;1mLast win date: " << "\u001b[0m " << user.lastwin << endl << "\u001b[36;1mTime spent on playing: " << "\u001b[0m " << playtime.minutes << " minutes and " << playtime.seconds << " seconds" << endl;
}


//struct to save history
struct history {
    string playername;
    string mapname;
    string result;
    string date;
    int playingtime;

};


//function to get the history frome file and save into a vector
vector <history>  gethistory() {
    ifstream historyfile("history.txt");
    vector <history> historyvec;
    history vecfill;
    for (int i = 0; i < 10; i++) {
        historyvec.push_back(vecfill);
    }
    string playingtime;
    for (int i = 0; i < 10; i++) {
        getline(historyfile, historyvec[i].playername);
        getline(historyfile, historyvec[i].mapname);
        getline(historyfile, historyvec[i].result);
        getline(historyfile, historyvec[i].date);
        getline(historyfile, playingtime);
        historyvec[i].playingtime = stoi(playingtime);
    }
    historyfile.close();
    return historyvec;
}


//function that updates history after any game and save into file
void updatehistory(string playername, string mapname, int result, int playingtime, vector<history> historyvec) {
    history thisgame;
    thisgame.playername = playername;
    thisgame.mapname = mapname;
    if (result == 1) {
        thisgame.result = "win";
    }
    else {
        thisgame.result = "loose";
    }
    thisgame.date = get_localtime();
    thisgame.playingtime = playingtime;
    historyvec.erase(historyvec.begin());
    historyvec.push_back(thisgame);
    ofstream historyfile("history.txt");
    for (int i = 0; i < 10; i++) {
        historyfile << historyvec[i].playername << "\n" << historyvec[i].mapname << "\n" << historyvec[i].result << "\n" << historyvec[i].date << "\n" << historyvec[i].playingtime << "\n";
    }

}



//function that shows game history
void showhistory(vector<history> vec) {
    cout << endl << "\u001b[36;1m********* GAME HISTORY ********\u001b[0m" << endl << endl;
    struct time playtime[10];
    for (int i = 9; i >= 0; i--) {
        playtime[i].minutes = vec[i].playingtime / 60;
        playtime[i].seconds = vec[i].playingtime % 60;
        if (i % 2 == 0) {
            cout << 10 - i << "\u001b[35;1m.Player name: " << "\u001b[0m " << vec[i].playername << endl << "\u001b[35;1mMap name: " << "\u001b[0m " << vec[i].mapname << endl << "\u001b[35;1mResult: " << "\u001b[0m " << vec[i].result << endl << "\u001b[35;1mDate: " << "\u001b[0m " << vec[i].date << endl << "\u001b[35;1mPlaying time: " << "\u001b[0m " << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
        else {
            cout << 10 - i << "\u001b[33;1m.Player name: " << "\u001b[0m " << vec[i].playername << endl << "\u001b[33;1mMap name: " << "\u001b[0m " << vec[i].mapname << endl << "\u001b[33;1mResult: " << "\u001b[0m " << vec[i].result << endl << "\u001b[33;1mDate: " << "\u001b[0m " << vec[i].date << endl << "\u001b[33;1mPlaying time: " << "\u001b[0m " << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
    }
}



//struct to save the top players information
struct topplayer {
    string name;
    int wincount;
    time_t playingtime;
};


//function to update top players after every game and save to a file
void updatetopplayers(userinfo user) {
    string wincount, winplayingtime;
    topplayer thisuser;
    thisuser.name = user.name;
    thisuser.wincount = user.wincount;
    thisuser.playingtime = user.winplayingtime;
    ifstream topplayerfile("topplayers.txt");
    topplayer tops[4];
    topplayer tmptops[3];
    int check = 0;

    for (int i = 0; i < 3; i++) {
        getline(topplayerfile, tops[i].name);
        getline(topplayerfile, wincount);
        getline(topplayerfile, winplayingtime);
        tops[i].wincount = stoi(wincount);
        tops[i].playingtime = stoi(winplayingtime);
        tmptops[i] = tops[i];
    }
    for (int i = 0; i < 3; i++) {
        if (thisuser.name == tops[i].name) {
            check++;
            break;

        }
    }

    topplayerfile.close();
    if (check == 0) {
        for (int i = 0; i < 3; i++) {


            if (thisuser.wincount >= tops[i].wincount) {
                if (thisuser.wincount > tops[i].wincount) {
                    auto buffer = tops[i];
                    tops[i] = thisuser;
                    tops[i + 1] = buffer;

                    break;
                }

                if (thisuser.wincount == tops[i].wincount) {
                    if (thisuser.playingtime < tops[i].playingtime) {
                        auto buffer = tops[i];
                        tops[i] = thisuser;
                        tops[i + 1] = buffer;
                        break;
                    }
                }
            }


        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (tops[i].name == thisuser.name) {
                int tartib = i;
                tops[i] = thisuser;
                for (int j = i - 1; j >= 0; j--) {
                    if (tops[tartib].wincount >= tops[j].wincount) {
                        if (tops[tartib].wincount > tops[j].wincount) {
                            auto buffer = tops[j];
                            tops[j] = tops[tartib];
                            tops[j + 1] = buffer;
                            tartib--;
                        }
                    }
                }
            }

        }
    }
    ofstream newtops("topplayers.txt");
    for (int i = 0; i < 3; i++) {
        newtops << tops[i].name << "\n" << tops[i].wincount << "\n" << tops[i].playingtime << "\n";
    }
    // int check1 = 0;
    // for (int i = 0; i < 3; i++) {
      //   if (tops[i].name != tmptops[i].name) {
      //       check1++;
           //  break;
      //   }
    // }
    // check1 = 0;
    // return check1;
}



//function that print the leaderboard
void showtopplayers() {
    cout << "\u001b[36;1m******** LEADER BOARD ********\u001b[0m" << endl << endl;
    ifstream topplayerfile("topplayers.txt");
    topplayer tops[3];
    struct time playtime[3];
    for (int i = 0; i < 3; i++) {
        string wincount, winplayingtime;
        getline(topplayerfile, tops[i].name);
        getline(topplayerfile, wincount);
        getline(topplayerfile, winplayingtime);
        tops[i].wincount = stoi(wincount);
        tops[i].playingtime = stoi(winplayingtime);
        playtime[i].minutes = tops[i].playingtime / 60;
        playtime[i].seconds = tops[i].playingtime % 60;
    }

    for (int i = 0; i < 3; i++) {
        if (1 % 2 == 0) {
            cout << endl << i + 1 << "\u001b[33;1m. Name:" << "\u001b[0m" << tops[i].name << endl << " \u001b[33;1mScore: " << "\u001b[0m" << tops[i].wincount << endl << "\u001b[33;1mPlaying time: " << "\u001b[0m" << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
        else {
            cout << endl << i + 1 << "\u001b[35;1m. Name:" << "\u001b[0m" << tops[i].name << endl << " \u001b[35;1mScore: " << "\u001b[0m" << tops[i].wincount << endl << "\u001b[35;1mPlaying time: " << "\u001b[0m" << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
    }

}





int main() {
    cout << endl << "\u001b[36;1m*************** WELCOME TO OUR MAZE PROJECT *************\u001b[0m" << endl << endl;
    cout << "Plaese enter your name: ";
    string username;
    getline(cin, username);
    username = space_to_underline(username);
    //cout << endl << endl;
menu:
    // cout<< endl << endl<< "\u001b[36;1m" <<"MENU:"<< endl << "1.Making a new maze" << endl << "2.Playground" << endl << "3.Solve a maze" << endl << "4.User information" << endl << "\5.History" << endl << "6.Leaderboard" << endl << " \u001b[31m7.Exit" << "\u001b[0m" << endl ;
    cout << "*******************************************************************************" << endl;
    cout << "*.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ --_ _-_ _- .'|   |.'|     |  _..  *" << endl;
    cout << "*    `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-_ _--_-_  .'  |.;'   |   _.!-'|   *" << endl;
    cout << "*      | `-!._  |  `;|  ;.   ______________________ ,'| .-' |   _!.-'     |   *" << endl;
    cout << "*..__  |     |`-!._ | `.| | |__________MENU________| |  . '|  _|.;'   |     _|*" << endl;
    cout << "*   |``..__ |    |`;.| -  |_|                      |_|'|  _|-|   |   _|..|'   *" << endl;
    cout << "*   |      |``--..|_ | `;.| | \u001b[35;1m1.Making a new maze\u001b[0m  | |.''   |_..!-'|     |    *" << endl;
    cout << "*   |      |     |   |`-,_|_|                      |_| .|-;'  |    |     |    *" << endl;
    cout << "*   |      |     |   |`-,_|_|     \u001b[34;1m2.Playground\u001b[0m     |_| .|-;'  |    |     |    *" << endl;
    cout << "*___|______|____-|.,.|,,|.| |                      | |,.,.,.,.!..__|_____|____*" << endl;
    cout << "*   |      |    -|.,.|,,|.| |    \u001b[36;1m3.Solve a maze\u001b[0m    | |,.,.,.,.!..  |     |    *" << endl;
    cout << "*      |     |    |  |  | |_|                      |_|  |   |   |    |      | *" << endl;
    cout << "*      |     |    |  |  | |_|  \u001b[32;1m4.User information\u001b[0m  |_|  |   |   |    |      | *" << endl;
    cout << "*      |     |    |..|-;  | |                      | |  `-..|   |    |      | *" << endl;
    cout << "*      |    _!.--'   | _ -|_|      \u001b[33;1m5.History\u001b[0m       |_|| ._   `'-|.._ |      | *" << endl;
    cout << "*     _!.-'|    | _.|   ; | |                      | |`.| `-._       |-.._  | *" << endl;
    cout << "*..--'     |  _.''|  .-| .|_|    \u001b[31;1m6.Leaderboard\u001b[0m     |_| .|`-.| ``._|       |   *" << endl;
    cout << "*   |      |.|    |.|  .| | |                      | |  |`. |`    |`      |   *" << endl;
    cout << "*   |  _.-'  |  .'  |.' |/|_|        \u001b[31m7.Exit\u001b[0m        |_|  | |`|  `,.|     -_|   *" << endl;
    cout << "*   |  _.-'  |  .'  |.' |/|_|                      |_|  | |`|  `,.|     -_|   *" << endl;
    cout << "*   |  _.-'  |  .'  |.' |/|_|  enter your choice:  |_| | |`|  `,. |     -_|   *" << endl;
    cout << "*  _-'|     !.'|  .'| .'| [ ]______________________[ ] |   `. | `._  |   `|._ *" << endl;
    cout << "*-'    |   .'   |.|  |/|   |                        |  |    |.|      |-       *" << endl;
    cout << "*      |_.'|   .' | .' | |                            |   |  `.    |`._     | *" << endl;
    cout << "*     .'   | .'   |/|  |                                | |`-   |`.|    `.  | *" << endl;
    cout << "*  _.'     -'|   .'  |                                    |  `  |  `.    |`.| *" << endl;
    cout << "*******************************************************************************" << endl;
    string choice;
    cin >> choice;
    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" && choice != "0") {
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" && choice != "0") {
            cout << endl << "invalid choice" << endl << "enter your choice: " << endl;
            cin >> choice;
        }
    }
    if (choice == "1") {
    newmaze:
        cout << endl << "\u001b[36;1m******** MAKING A NEW MAZE ********\u001b[0m" << endl;
        cout << endl << "1.easy mode" << endl << "2.hard mode" << endl << "enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            vector<vector<int>> maze = easymazemaker();
            printmaze(maze, -3, 3);

        }
        else if (choice == "2") {
            vector<vector<int>> maze = hardmazemaker();
            int min = minelement(maze);
            int max = maxelement(maze);
            printmaze(maze, min, max);
        }
        else {
            while (choice != "1" && choice != "2") {
                cout << endl << "invalid choice" << endl << "enter 1 for making a easy maze and 2 for making a hard maze, also you can enter '0' to come back to menu :" << endl;
                cin >> choice;
                if (choice == "0")
                {
                    goto menu;
                }
            }

            if (choice == "1") {
                vector<vector<int>> maze = easymazemaker();
                printmaze(maze, -3, 3);
            }
            else if (choice == "2") {
                vector<vector<int>> maze = hardmazemaker();
                int min = minelement(maze);
                int max = maxelement(maze);
                printmaze(maze, min, max);
            }
        }
        cout << "Well done!" << endl << "Coming back to menu..." << endl;
        cout << endl;
        goto menu;
    }

    else if (choice == "2") {
    playground:
        cout << endl << "\u001b[36;1m******** PLAYGROUND ********\u001b[0m" << endl;
        cout << endl << "1.choose from existing map" << endl << "2.import a custom map" << endl << "enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "invalid choice" << endl << "enter 1 for playing with existing maps and 2 for importing a custom map, or press 0 for coming back to menu:" << endl;
                cin >> choice;
                if (choice == "0") {
                    goto menu;
                }
            }
        }
        if (choice == "1") {
            cout << endl;
            string mapname = choosmap();
            vector<vector<int>> maze = filetovec(mapname);
            int min = minelement(maze);
            int max = maxelement(maze);
            int steps = getstepsfromfile(mapname);
            auto start = high_resolution_clock::now();
            int result = play(maze, min, max, steps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            int playingtime = duration.count();
            if (playingtime < 60) {
                cout << endl << "your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                struct time playtime;
                playtime.minutes = playingtime / 60;
                playtime.seconds = playingtime % 60;
                cout << endl << "your playing time: " << playtime.minutes << " minutes and " << playtime.seconds << "seconds" << endl;
            }
            userinfo thisuser = getuserinfo(username);
            updateuserinfo(thisuser, result, playingtime);
            thisuser = getuserinfo(username);
            vector<history> gamehistory = gethistory();
            updatehistory(username, mapname, result, playingtime, gamehistory);
            updatetopplayers(thisuser);
            cout << endl << "\u001b[36;1m***YOUR UPDATED USER INFORMATION***\u001b[0m" << endl;
            printuserinfo(thisuser);
            cout << endl;
            cout << endl << endl << "Good job!" << endl << "Going back to menu..." << endl;
            cout << endl;
            goto menu;

        }
        else if (choice == "2") {
            cout << endl;
            string mapname;
            cout << "Enter the name of your file: ";
            cin >> mapname;
            cout << endl;
            vector<vector<int>> maze = userfiletovec(mapname);
            int min = minelement(maze);
            int max = maxelement(maze);
            int steps = getstepsfromfile(mapname);
            auto start = high_resolution_clock::now();
            int result = play(maze, min, max, steps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            int playingtime = duration.count();
            if (playingtime < 60) {
                cout << endl << "your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                struct time playtime;
                playtime.minutes = playingtime / 60;
                playtime.seconds = playingtime % 60;
                cout << endl << "your playing time: " << playtime.minutes << " minutes and " << playtime.seconds << "seconds" << endl;
            }
            userinfo thisuser = getuserinfo(username);
            updateuserinfo(thisuser, result, playingtime);
            thisuser = getuserinfo(username);
            vector<history> gamehistory = gethistory();
            updatehistory(username, mapname, result, playingtime, gamehistory);
            updatetopplayers(thisuser);
            cout << endl << "\u001b[36;1m***YOUR UPDATED USER INFORMATION***\u001b[0m" << endl;
            printuserinfo(thisuser);
            cout << endl;
            cout << endl << endl << "Good job!" << endl << "Going back to menu..." << endl;
            cout << endl;
            goto menu;


        }
    }
    else if (choice == "3") {
    solve:
        cout << endl << "\u001b[36;1m******** MAZE SOLVING ********\u001b[0m" << endl;
        cout << endl << "1.choose from existing map" << endl << "2.import a custom map" << endl << "0.back to menu" << endl << "enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "invalid choice" << endl << "enter 1 for solving existing maps and 2 for importing a custom map or you can go to menu with pressing 0:";
                cin >> choice;
                if (choice == "0")
                {
                    goto menu;
                }
            }
        }
        if (choice == "1") {
            string mapname = choosmap();
            vector<vector<int>> maze = filetovec(mapname);
            vector<vector<int>> maze1;
            int min = minelement(maze);
            int max = maxelement(maze);
            int steps = getstepsfromfile(mapname);
            for (int i = 0; i < maze.size(); i++) {
                maze1.push_back(vector<int>());
                for (int j = 0; j < maze[0].size(); j++) {
                    maze1[i].push_back(maze[i][j]);
                }
            }
            bool sol = mazesolution(maze, 0, 0, maze.size() - 1, maze[0].size() - 1, steps, min, max, 0, maze1);

            printmaze(maze1, min, max);

        }
        else if (choice == "2") {
            string mapname;
            cout << "Enter the name of your file: ";
            cin >> mapname;
            cout << endl;
            vector<vector<int>> maze = userfiletovec(mapname);
            vector<vector<int>> maze1;
            int min = minelement(maze);
            int max = maxelement(maze);
            int steps = getstepsfromfile(mapname);
            for (int i = 0; i < maze.size(); i++) {
                maze1.push_back(vector<int>());
                for (int j = 0; j < maze[0].size(); j++) {
                    maze1[i].push_back(maze[i][j]);
                }
            }
            bool sol = mazesolution(maze, 0, 0, maze.size()-1, maze[0].size()-1, steps, min, max, 0, maze1);
            printmaze(maze1, min, max);

        }

        cout << endl << endl << "Hihihihi... =D " << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;
    }

    else if (choice == "4") {
    userinfo:
        userinfo thisuserinfo = getuserinfo(username);
        cout << endl << "Here you are: " << endl;
        cout << endl << "\u001b[36;1m*******YOUR USER INFORMATION********\u001b[0m" << endl;
        printuserinfo(thisuserinfo);
        cout << endl << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;

    }

    else if (choice == "5") {
    his:
        vector <history> historyvec = gethistory();
        cout << endl << "Here you are: " << endl;
        showhistory(historyvec);
        cout << endl << endl << "Going back to menu..." << endl;
        goto menu;
    }

    else if (choice == "6") {
    tops:
        showtopplayers();
        cout << endl << endl << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;
    }

    else if (choice == "7") {
        return 0;
    }


    return 0;
}




