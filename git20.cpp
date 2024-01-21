int main() {
    menu:
    cout << "1.making a new maze" << endl << "2.playground" << endl << "3.solve a maze" << endl << "4.user information" << endl << "5.history" << endl << "6.leaderboard" << endl << "7.exit" << endl ;
    cout << "enter your choice: " << endl;
    string choice;
    cin >> choice;
    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7") {
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7") {
            cout << endl << "invalid choice" << endl << "enter your choice: " << endl;
            cin >> choice;
        }
    }
    if (choice == "1") {
        newmaze:
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
            while (choice != "1" && choice != "2" ) {
                cout << endl << "invalid choice" << endl << "enter 1 for making a easy maze and 2 for making a hard maze, also you can enter '0' to come back to menu :"<< endl;
                cin >> choice;
                if(choice == "0")
                {goto menu;}
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
        cout<<"Well done!"<< endl <<"Coming back to menu..." << endl ;
        cout << endl; 
        goto menu;
    }

    else if (choice == "2") {
        playground:
        cout << endl << "1.choose from existing map" << endl << "2.import a custom map" << endl << "enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "invalid choice" << endl << "enter 1 for playing with existing maps and 2 for importing a custom map, or press 0 for coming back to menu:"<<  endl;
                cin >> choice;
                if(choice == "0"){
                    goto menu;
                }
            }
        }
        if (choice == "1") {
            string username;
            cout << "Enter your name: ";
            cin >> username;
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
                cout << "your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                double time = playingtime / 60;
                cout << "your playing time: " << time << " minutes" << endl;
            }
            userinfo thisuser = getuserinfo(username);
            updateuserinfo(thisuser, result, playingtime);
            thisuser = getuserinfo(username);
            vector<history> gamehistory = gethistory();
            updatehistory(username, mapname, result, playingtime, gamehistory);
            updatetopplayers(thisuser);
            cout <<endl<< "*YOUR UPDATED USER INFORMATION*" << endl;
            printuserinfo(thisuser);


        }
        else if (choice == "2") {
            string username;
            cout << "Enter your name: ";
            cin >> username;
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
                cout << "your playing time: " << playingtime << " seconds" << endl;
            }
            else {
                double time = playingtime / 60;
                cout << "your playing time: " << time << " minutes" << endl;
            }
            userinfo thisuser = getuserinfo(username);
            updateuserinfo(thisuser, result, playingtime);
            thisuser = getuserinfo(username);
            vector<history> gamehistory = gethistory();
            updatehistory(username, mapname, result, playingtime, gamehistory);
            updatetopplayers(thisuser);
            cout <<endl<< "*YOUR UPDATED USER INFORMATION*" << endl;
            printuserinfo(thisuser);

        }

        cout<< endl;
        cout<< "Good job!" << endl << "Going back to menu..." << endl;
        cout<< endl;
        goto menu;

    }