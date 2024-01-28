

//function that print the leaderboard
void showtopplayers() {
    cout << "\u001b[36;1m******** LEADER BOARD ********\u001b[0m" << endl << endl;
    ifstream topplayerfile("topplayers.txt");
    topplayer tops[3];
    struct time playtime[3];
    for (int i = 0; i < 3; i++) {
        string wincount, winplayingtime;
        getline(topplayerfile, tops[i].name);
        getline(topplayerfile, wincount);
        getline(topplayerfile, winplayingtime);
        tops[i].wincount = stoi(wincount);
        tops[i].playingtime = stoi(winplayingtime);
        playtime[i].minutes = tops[i].playingtime / 60;
        playtime[i].seconds = tops[i].playingtime % 60;
    }

    for (int i = 0; i < 3; i++) {
        if (1 % 2 == 0) {
            cout << endl << i + 1 << "\u001b[33;1m. Name:" << "\u001b[0m" << tops[i].name << endl << " \u001b[33;1mScore: " << "\u001b[0m" << tops[i].wincount << endl << "\u001b[33;1mPlaying time: " << "\u001b[0m" << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
        else {
            cout << endl << i + 1 << "\u001b[35;1m. Name:" << "\u001b[0m" << tops[i].name << endl << " \u001b[35;1mScore: " << "\u001b[0m" << tops[i].wincount << endl << "\u001b[35;1mPlaying time: " << "\u001b[0m" << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
    }

}

