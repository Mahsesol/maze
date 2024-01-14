struct history{
    string playername;
    string mapname;
    string result;
    string date;
    time_t playingtime;
    
};


vector <history>  gethistory(){
    ifstream historyfile("/Users/liliarouhi/Desktop/history.txt");
    vector <history> historyvec;
    history vecfill;
    for(int i=0; i<10; i++){
        historyvec.push_back(vecfill);
    }
    string playingtime;
    for(int i=0; i<10; i++){
        getline(historyfile , historyvec[i].playername);
        getline(historyfile , historyvec[i].mapname);
        getline(historyfile , historyvec[i].result);
        getline(historyfile , historyvec[i].date);
        getline(historyfile , playingtime);
        historyvec[i].playingtime = stoi(playingtime);
    }
    historyfile.close();
    return historyvec;
}

void updatehistory(string playername , string mapname , int result, time_t playingtime , vector<history> historyvec){
    history thisgame;
    thisgame.playername = playername;
    thisgame.mapname = mapname;
    if(result == 1){
        thisgame.result = "win";
    }else{
        thisgame.result = "loose";
    }
    thisgame.date = get_localtime();
    thisgame.playingtime = playingtime;
    historyvec.erase(historyvec.begin());
    historyvec.push_back(thisgame);
    ofstream historyfile ("/Users/liliarouhi/Desktop/history.txt");
    for(int i=0; i<10; i++){
        historyfile << historyvec[i].playername << "\n" << historyvec[i].mapname << "\n" << historyvec[i].result << "\n" << historyvec[i].date << "\n" << historyvec[i].playingtime << "\n";
    }
    
}

void showhistory (vector<history> vec){
    cout<< "*GAME HISTORY*" << endl;
    for(int i=9; i>=0; i--){
        cout << 10-1 << ".playername: " << vec[i].playername << endl << "mapname: " << vec[i].mapname << endl << "result: " << vec[i].result << endl << "date: " << vec[i].date << endl << "playingtime: " << vec[i].playingtime << endl;
    }
}