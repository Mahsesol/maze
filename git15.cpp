void printuserinfo(userinfo user) {
    string timeunit;
    double time;
    if (user.playingtime >= 60) {
        time = user.playingtime / 60;
        timeunit = "minutes";
    }
    else {
        time = user.playingtime;
        timeunit = "seconds";
    }
    cout << endl <<  "name: " << user.name << endl << "play count: " << user.playcount << endl << "win count: " << user.wincount << endl << "last win date: " << user.lastwin << endl << "time spent on playing: " << time << " " << timeunit << endl;
}
