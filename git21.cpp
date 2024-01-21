     else if (choice == "3") {
        solve:
        cout << endl << "1.choose from existing map" << endl << "2.import a custom map" << endl << "enter your choice: ";
        cin >> choice;
        if (choice != "1" && choice != "2") {
            while (choice != "1" && choice != "2") {
                cout << endl << "invalid choice" << endl << "enter 1 for solving existing maps and 2 for importing a custom map or you can go to menu with pressing 0:";
                cin >> choice;
                if(choice == "0")
                {goto menu; }
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
            bool sol = mazesolution(maze, 0, 0, maze.size(), maze[0].size(), steps, min, max, 0, maze1);
            printmaze(maze1, min, max);

        }
    
        cout<<"Hihihihi... =D " << endl << "Going back to menu..." << endl;
        cout<< endl;
        goto menu;
    }
    
    else if (choice == "4") {
        userinfo:
        cout << "enter your name:";
        string name;
        cin >> name;
        userinfo thisuserinfo = getuserinfo(name);
        cout<< endl << "Here you are: " << endl;
        printuserinfo(thisuserinfo);
         cout << "Going back to menu..." << endl;
         cout<< endl;
        goto menu;

    }

    else if (choice == "5") {
        his:
        vector <history> historyvec = gethistory();
        cout << endl << "Here you are: " << endl;
        showhistory(historyvec);
        cout << "Going back to menu..." << endl;
        goto menu;
    }
    
    else if (choice == "6") {
        top:
        showtopplayers();
         cout << endl << "Going back to menu..." << endl;
         cout<< endl;
        goto menu;
    }

    else if (choice == "7") {
        return 0;
    }


    return 0;
}



