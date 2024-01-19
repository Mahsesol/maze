void printmaze(const vector<vector<int>>& array ,int min,int max) {
     const int numRows = array.size();
    const int numCols = (numRows > 0) ? array[0].size() : 0;

    /v/ ANSI escape codes for text color
    const char* greenText = "\033[1;32m";
    const char* redText = "\033[1;31m";
    const char* yellowText = "\033[1;33m";
    const char* resetText = "\033[0m";

    // Print the top border
    cout << "*";
    for (int j = 0; j < numCols; ++j) {
        cout << "-----*";
    }
    cout << endl;

    
    // Print the array with borders
    for (int i = 0; i < numRows; ++i) {
        cout << "|";
        for (int j = 0; j < numCols; ++j) {
            int currentValue = array[i][j];
            if(currentValue==0){
                cout<< yellowText << setw(5) << currentValue << resetText<< "|";
            }

           else if (i == numRows - 1 && j == numCols - 1) {
                // Bottom right corner: print in red
                cout << redText << setw(5) << currentValue << resetText << "|";
            } else {
                // Check if the value is less than -5
                if (currentValue < min && currentValue!=0) {
                    
                   
                    cout << greenText << setw(5) << currentValue+abs(max)*2+abs(min)*2+1 << resetText << "|";
                } else {
                    // Otherwise, print normally
                    cout << setw(5) << currentValue << "|";
                }
            }
        }
        cout << endl;

        // Print the mid border
        cout << "*";
        for (int j = 0; j < numCols; ++j) {
            cout << "-----*";
        }
        cout << endl;
    };
    }
