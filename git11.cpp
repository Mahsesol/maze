
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
