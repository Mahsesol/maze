
//function to print user information
void printuserinfo(userinfo user) {
    //  cout << "\u001b[36m******** YOUR INFORMATION ********" << endl;
    struct time playtime;
    playtime.minutes = user.playingtime / 60;
    playtime.seconds = user.playingtime % 60;
    cout << endl << "\u001b[36;1mName: " << "\u001b[0m " << user.name << endl << "\u001b[36;1mPlay count: " << "\u001b[0m " << user.playcount << endl << "\u001b[36;1mWin count: " << "\u001b[0m " << user.wincount << endl << "\u001b[36;1mLast win date: " << "\u001b[0m " << user.lastwin << endl << "\u001b[36;1mTime spent on playing: " << "\u001b[0m " << playtime.minutes << " minutes and " << playtime.seconds << " seconds" << endl;
}


