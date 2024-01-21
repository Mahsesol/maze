void showtopplayers() {
    ifstream topplayerfile("topplayers.txt");
    string timeunit[3];
    double time[3];
    topplayer tops[3];
    for (int i = 0; i < 3; i++) {
        string wincount, winplayingtime;
        getline(topplayerfile, tops[i].name);
        getline(topplayerfile, wincount);
        getline(topplayerfile, winplayingtime);
        tops[i].wincount = stoi(wincount);
        tops[i].playingtime = stoi(winplayingtime);
        if (tops[i].playingtime >= 60) {
            time[i] = tops[i].playingtime / 60;
            timeunit[i] = "minutes";
        }
        else {
            time[i] = tops[i].playingtime;
            timeunit[i] = "seconds";
        }
    }

    for (int i = 0; i < 3; i++) {
        cout<< endl << i + 1 << "." << tops[i].name << endl << "score: " << tops[i].wincount << endl << "playing time: " << time[i] << " " << timeunit[i] << endl;
    }
}