void updatehistory(string playername, string mapname, int result, int playingtime, vector<history> historyvec) {
    history thisgame;
    thisgame.playername = playername;
    thisgame.mapname = mapname;
    if (result == 1) {
        thisgame.result = "win";
    }
    else {
        thisgame.result = "loose";
    }
    thisgame.date = get_localtime();
    thisgame.playingtime = playingtime;
    historyvec.erase(historyvec.begin());
    historyvec.push_back(thisgame);
    ofstream historyfile("history.txt");
    for (int i = 0; i < 10; i++) {
        historyfile << historyvec[i].playername << "\n" << historyvec[i].mapname << "\n" << historyvec[i].result << "\n" << historyvec[i].date << "\n" << historyvec[i].playingtime << "\n";
    }

}