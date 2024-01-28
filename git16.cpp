
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


