vector<vector<int>> userfiletovec(string& mapname) {
    vector<vector<int>> vec;
    string checktxt = mapname.substr(mapname.size() - 4, 4);
    if (checktxt != ".txt") {
        mapname = mapname + ".txt";
    }
    int exists = exists_test(mapname);
    if (exists == 0) {
        cout << "file does not exist!";
        while (exists == 0) {
            cout << "enter the name of your file correctly or enter '>' to exit: ";
            cin >> mapname;
            if (mapname == ">") {
                vec.push_back({ 0 });
                return vec;
            }
            else {
                checktxt = mapname.substr(mapname.size() - 4, 4);
                if (checktxt != ".txt") {
                    mapname = mapname + ".txt";
                }
                exists = exists_test(mapname);
            }
        }
    }
    ifstream file(mapname);
    string row, col;
    string steps;
    file >> row >> col >> steps;
    int row1 = stoi(row);
    int col1 = stoi(col);
    string** arr = new string * [row1];
    for (int i = 0; i < row1; i++) {
        arr[i] = new string[col1];
    }
    for (int i = 0; i < stoi(row); i++) {
        for (int j = 0; j < stoi(col); j++) {
            file >> arr[i][j];
        }
    }
    for (int i = 0; i < stoi(row); i++) {
        vec.push_back(vector<int>());
        for (int j = 0; j < stoi(col); j++) {
            int temp = stoi(arr[i][j]);
            vec[i].push_back(temp);
        }
    }
    mapname.erase(mapname.size() - 4, 4);
    return vec;
}
