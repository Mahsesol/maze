void showhistory(vector<history> vec) {
    cout << endl << "*GAME HISTORY*" << endl;
    string timeunit[10];
    double time[10];
    for (int i = 9; i >= 0; i--) {
        if (vec[i].playingtime >= 60) {
            time[i] = vec[i].playingtime / 60;
            timeunit[i] = "minutes";
        }
        else {
            time[i] = vec[i].playingtime;
            timeunit[i] = "seconds";
        }
        cout << 10 - i << ".playername: " << vec[i].playername << endl << "mapname: " << vec[i].mapname << endl << "result: " << vec[i].result << endl << "date: " << vec[i].date << endl << "playingtime: " << time[i] << " " << timeunit[i] << endl << endl;
    }
}
