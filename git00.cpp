#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include<cmath>
#include <chrono>
#include <thread>
#include <limits>
#include <fstream>
#include <ctime>
#include <chrono>
#include <cstdio>


using namespace std;
using namespace std::chrono;


void newmap(vector<vector<int>> vec, int row, int col, int steps,string mapname);

const int SPECIAL_VALUE = std::numeric_limits<int>::max();
