
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
    cout << "*   |  _.-'  |  .'  |.' |/|_|  Enter your choice:  |_| | |`|  `,. |     -_|   *" << endl;
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
            cout << endl << "Invalid choice" << endl << "Enter your choice: " << endl;
            cin >> choice;
        }
    }
    if (choice == "1") {
    newmaze:
        cout << endl << "\u001b[36;1m******** MAKING A NEW MAZE ********\u001b[0m" << endl;
        cout << endl << "1.Easy mode" << endl << "2.Hard mode" << endl << "Enter your choice: ";
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
                cout << endl << "Invalid choice" << endl << "Enter 1 for making a easy maze and 2 for making a hard maze, also you can enter '0' to come back to menu :" << endl;
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
        cout << endl << "1.Choose from existing map" << endl << "2.Import a custom map" << endl << "Enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "Invalid choice" << endl << "Enter 1 for playing with existing maps and 2 for importing a custom map, or press 0 for coming back to menu:" << endl;
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
                cout << endl << "Your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                struct time playtime;
                playtime.minutes = playingtime / 60;
                playtime.seconds = playingtime % 60;
                cout << endl << "Your playing time: " << playtime.minutes << " minutes and " << playtime.seconds << "seconds" << endl;
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
            if (maze.size() == 1) {
                goto menu;
            }
            int min = minelement(maze);
            int max = maxelement(maze);
            int steps = getstepsfromfile(mapname);
            auto start = high_resolution_clock::now();
            int result = play(maze, min, max, steps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            int playingtime = duration.count();
            if (playingtime < 60) {
                cout << endl << "Your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                struct time playtime;
                playtime.minutes = playingtime / 60;
                playtime.seconds = playingtime % 60;
                cout << endl << "Your playing time: " << playtime.minutes << " minutes and " << playtime.seconds << "seconds" << endl;
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
        cout << endl << "1.Choose from existing map" << endl << "2.Import a custom map" << endl << "0.Back to menu" << endl << "Enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "Invalid choice" << endl << "Enter 1 for solving existing maps and 2 for importing a custom map or you can go to menu with pressing 0:";
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
            if (maze.size() == 1) {
                goto menu;
            }
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

        cout << endl << endl << "Hihihihi... =D " << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;
    }
