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
        cin >> play;
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
            cout << "Do you want to fly? =) " << endl << "Me too!" << endl;
            cout << "Restart playing: " << endl;
            cout << "press w to go up" << endl;
            cout << "press s to go down" << endl;
            cout << "press a to go left" << endl;
            cout << "press d to go right" << endl;
        }
  
    }

    if (steps == 0 && x == maze.size() - 1 && y == maze[0].size() - 1 && maze[x][y] == sum) {
        cout << "you won :D" << endl;
        return 1;
    }
    else {
        cout << "you loose :("<< endl ;
        return 0;
    }
}