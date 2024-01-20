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

