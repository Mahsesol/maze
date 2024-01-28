
//function that add any new map made with program in the maps list in playground
void newmap(vector<vector<int>> vec, int row, int col, int steps, string mapname) {
    mapname = mapname + ".txt";
    ofstream file(mapname);
    file << row << " " << col << '\n' << steps << '\n';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            file << vec[i][j] << " ";
        }
        file << '\n';
    }
    ofstream mapsfile("maps.txt", ios::app);
    mapsfile << "\n" << mapname;
}

