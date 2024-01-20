int getstepsfromfile(string mapname) {
    string checktxt = mapname.substr(mapname.size() - 4, 4);
    if (checktxt != ".txt") {
        mapname = mapname + ".txt";
    }
    ifstream file(mapname);
    string row, col;
    string steps;
    file >> row >> col >> steps;
    int steps1 = stoi(steps);
    return steps1;
}