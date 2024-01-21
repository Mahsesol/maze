struct history {
    string playername;
    string mapname;
    string result;
    string date;
    int playingtime;

};

vector <history>  gethistory() {
    ifstream historyfile("history.txt");
    vector <history> historyvec;
    history vecfill;
    for (int i = 0; i < 10; i++) {
        historyvec.push_back(vecfill);
    }
    string playingtime;
    for (int i = 0; i < 10; i++) {
        getline(historyfile, historyvec[i].playername);
        getline(historyfile, historyvec[i].mapname);
        getline(historyfile, historyvec[i].result);
        getline(historyfile, historyvec[i].date);
        getline(historyfile, playingtime);
        historyvec[i].playingtime = stoi(playingtime);
    }
    historyfile.close();
    return historyvec;
}