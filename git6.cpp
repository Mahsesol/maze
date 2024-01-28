

//function that allows user to choos from existing maps in maps list
string choosmap() {
    string str;
    ifstream file("maps.txt");
    vector<string> vec;
    while (getline(file, str)) {
        if (!str.empty()) {
            vec.push_back(str);
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << i + 1 << "." << vec[i] << endl;
    }
    string choice;
    cout << "enter your choice: ";
    cin >> choice;
    string mapname;
    if (check_number(choice) == 0 || stoi(choice) < 1 || stoi(choice) > vec.size()) {
        while (check_number(choice) == 0 || stoi(choice) < 1 || stoi(choice) > vec.size()) {
            cout << endl << "invalid choice" << endl << "enter yoru choice:";
            cin >> choice;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (i + 1 == stoi(choice)) {
            mapname = vec[i];
            break;
        }
    }

    return mapname;
}


//function that checks if a file exists or not
inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}



//function that turn user file into a maze (for solving or playing)
vector<vector<int>> userfiletovec(string& mapname) {
    vector<vector<int>> vec;
    string checktxt;
    if(mapname.size() > 4){
        checktxt = mapname.substr(mapname.size() - 4, 4);
        if (checktxt != ".txt") {
            mapname = mapname + ".txt";
        }
    }else{
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
                if(mapname.size() > 4){
                    checktxt = mapname.substr(mapname.size() - 4, 4);
                    if (checktxt != ".txt") {
                        mapname = mapname + ".txt";
                    }
                }else{
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


