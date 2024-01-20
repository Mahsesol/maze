vector<vector<int>> easymazemaker() {
    random_device rd;
    mt19937 g(rd());
    string mapname;
    cout << "Enter your map name: ";
    cin >> mapname;
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

   
    vector<vector<int>> maze(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = SPECIAL_VALUE;
        }
    }

    vector<int> tartib;
    uniform_int_distribution<int> distribution(-3, 3);
    uniform_int_distribution<int> distribution2(2, 5);
    

    for (int i = 0; i < col - 1; i++) { tartib.push_back(1); }
    for (int i = 0; i < row - 1; i++) { tartib.push_back(0); }
    int y = 0;
    int x = 0;
    int val = 0;

    shuffle(tartib.begin(), tartib.end(), g);
   

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
