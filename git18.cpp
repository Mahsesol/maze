

//function that shows game history
void showhistory(vector<history> vec) {
    cout << endl << "\u001b[36;1m********* GAME HISTORY ********\u001b[0m" << endl << endl;
    struct time playtime[10];
    for (int i = 9; i >= 0; i--) {
        playtime[i].minutes = vec[i].playingtime / 60;
        playtime[i].seconds = vec[i].playingtime % 60;
        if (i % 2 == 0) {
            cout << 10 - i << "\u001b[35;1m.Player name: " << "\u001b[0m " << vec[i].playername << endl << "\u001b[35;1mMap name: " << "\u001b[0m " << vec[i].mapname << endl << "\u001b[35;1mResult: " << "\u001b[0m " << vec[i].result << endl << "\u001b[35;1mDate: " << "\u001b[0m " << vec[i].date << endl << "\u001b[35;1mPlaying time: " << "\u001b[0m " << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
        else {
            cout << 10 - i << "\u001b[33;1m.Player name: " << "\u001b[0m " << vec[i].playername << endl << "\u001b[33;1mMap name: " << "\u001b[0m " << vec[i].mapname << endl << "\u001b[33;1mResult: " << "\u001b[0m " << vec[i].result << endl << "\u001b[33;1mDate: " << "\u001b[0m " << vec[i].date << endl << "\u001b[33;1mPlaying time: " << "\u001b[0m " << playtime[i].minutes << " minutes and  " << playtime[i].seconds << " seconds" << endl << endl;
        }
    }
}

