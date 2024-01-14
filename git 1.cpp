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
void blockmaker(vector<vector<int>>& matrix, int n) {
        int count = 0;
        srand(std::time(0));

        while (count < n) {
                 size_t i = rand() % matrix.size();
                 size_t j = rand() % matrix[i].size();

                 if (matrix[i][j]==SPECIAL_VALUE) {
                  matrix[i][j] = 0;
                  ++count;
                 }
        }
}