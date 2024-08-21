# Maze
[![AGPL License](https://img.shields.io/badge/IUST-Mathemati%20c:-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)

An enjoyable funny exercise for your mind.
Here is a 2D maze of number which is improving your creativity, problem solving skills, memory, hand-eye coordination and... .  
Beside all its a good hobby for your free times!


![Screenshot (5)](https://github.com/Mahsesol/maze/assets/154425249/887643dd-1162-45d7-8c9d-b51c7a12d8f4)



## Explanation
  When you play this game at first you see a menu which guid you to chose a number, then you should share your chosen number with maze by clicking on that on your keyboard.  
Number "1" is going to make a maze table az your taste. It include two parts, hard part and easy one.  
Number "2" is guiding you to playground. You can start playing here.  
Number "3" is related to maze solutions.This part show maze solution on your screan.    
With using number "4" you can see users informations such as name, play count, win count,... .  
"5" is  history and "6" is leader board. By using first number you are able to see some information like players name, 
maps name, result,... of ten last game and second one is using to see three top players in leader board.  
Last choice, number "7" is using to exsiting from code.  
If you are curious about details of the action behind each number and function, after checking codes, check "functions" part here.  
Just remember these points before playing:
- Copy "history.txt" and "topplayers.txt" and "maps.txt" and "username.txt" files on your PC.  
- For playing on your own maze playground, you should make a txt file before to chose. the first line of this file should be row and col with one space between them, next line should be steps as a number, then we will have the maze table as a matrix. it is going to be some thing like this:

![photo9408583910](https://github.com/Mahsesol/maze/assets/154425249/d660cdd7-8e6c-41f5-8e70-66d1859a7730)

- Avoid using the same names for maps and usernames. with doing that one of the files will be missed.
- If code didnt work well, check Q&A part.

Hope you enjoy!  

## Repository files

- main.cpp: all the code of project  
- TXT folder: this folder include row txt files that we add "1" at the end of each name to preventing probably problems.  
-   ...(MapsName).txt: there are some ready maze tables. this file is making by itself.  
-   ...(UserNames).txt: user informations in txt files for each guy. this file is making by itself.  
-   maps.txt: it keeps saved maps.  
-   history.txt: it keeps the history of plays.  
-   topplayers.txt: it keeps three top players.
-   username.txt: it save each player name as a list and update it each time.


  
## Features

- You are able to see the history of game.
- You can see leader board.
- You can see each maze solution.
- You are able to see each plays time spent and campare with your previos record.
- You can personalize your table of number (playground).
- you are able to chose a map or user name more than one word.



## 🛠 Functions

```cpp
bool check_number(string str);
```
The program contains a function named check_number that takes a string as input and returns a boolean value indicating whether the string represents a number.

```cpp
string space_to_underline(string str) 
```
It takes a string str as input and returns the modified string with spaces replaced by underscores.  
Ths function allows you to have map and user names in two word  or even more.

```cpp
int minelement(vector<vector<int>> matrix);
```
The minelement function takes a matrix as input, represented by a vector of vectors of integers (vector<vector<int>>). It initializes the min variable with the maximum possible integer value using std::numeric_limits<int>::max(). then iterates through each row of the matrix using the for_each algorithm from the C++ Standard Library. For each row, it finds the minimum element using the min_element algorithm and compares it with the current minimum value stored in the min variable. If the found minimum element is smaller than the current minimum, it updates the min variable.  
Finally, the function returns the minimum element found in the matrix.

```cpp
int maxelement(vector<vector<int>> matrix);
```
This Function is finding the maximum element in a matrix.

```cpp
void newmap(vector<vector<int>> vec, int row, int col, int steps, string mapname);
```
Its related to the process of creating a map and saving it to a file.

```cpp
bool isValid(int x, int y, int rows, int cols);
```
This function is used to check whether a given position (x, y) is valid within a grid of size rows by cols.

```cpp
bool way(vector<vector<int>>& maze, int x, int y, int destX, int destY, int steps);
```
We have a maze represented by a 2D vector of integers. The maze contains walls represented by 0s and open paths represented by 1s. The goal is to find a path from a starting position (x, y) to a destination position (destX, destY) within a given number of steps.

```cpp
void blockmaker(vector<vector<int>>& matrix, int n);
```
Blockmaker function, which takes a 2D vector matrix and an integer n as parameters. The matrix represents the matrix in which we want to create blocks, and n represents the number of blocks to create.

```cpp
vector<vector<int>> easymazemaker();
```
 We will create a maze with random paths. The maze will be represented as a 2D vector, where each element represents a cell in the maze. The goal is to navigate from the top-left cell to the bottom-right cell, accumulating the values of the cells along the path.
 

```cpp
vector<vector<int>> hardmazemaker();
```
The program will prompt the user to enter various parameters such as the size of the maze, the minimum and maximum values for the maze elements, the number of steps in the path, and the minimum and maximum number of blocks in the maze. The program will then generate a hard maze based on these parameters.

```cpp
bool mazesolution(vector<vector<int>>& maze, int x, int y, int destX, int destY, int steps, int min, int max, int sum, vector<vector<int>>& maze1) ;
```
The mazesolution function starts with some base cases to check for invalid conditions. If any of these conditions are met, the function returns false. These base cases include:  
Checking if the current coordinates are out of bounds of the maze.  
Checking if the current cell value is less than the minimum allowed value and not the destination cell.  
Checking if the current cell value is 0, indicating a blocked cell.  
Checking if the number of steps is negative.  
If none of the base cases are met, the function checks if the current coordinates are the destination coordinates and if the sum of the costs of the visited cells is equal to the current sum and the number of steps is 0. If this condition is met, the function stores the solution path in the maze1 vector and returns true.  
If the base cases are not met and the destination is not reached, the function performs recursive backtracking. It adds the cost of the current cell to the sum, subtracts a change value from the current cell value, and recursively calls the mazesolution function for the adjacent cells (up, down, left, and right). If any of these recursive calls return true, indicating a valid path, the function returns true.  
If no valid path is found, the function backtracks by adding the change value back to the current cell value and subtracting the cost of the current cell from the sum. It then returns false.  

```cpp
void printmaze(const vector<vector<int>>& array, int min, int max);
```
We have a function called printmaze that is responsible for printing a maze represented by a 2D vector. The maze is printed with different colors and formatting to highlight specific elements.

```cpp
bool isvalidmoveplay(vector<vector<int>>& maze, int x, int y, int minyy);
```
The function returns a boolean value indicating whether the move is valid or not.

```cpp
void printmazeplay(const vector<vector<int>>& array, int min, int max, int x, int y) ;
```
We have a function called printmazeplay that takes in a 2D vector array, along with some other parameters. The function's purpose is to print the maze represented by the array with colorful borders. The maze is printed in the console, and different colors are used to highlight specific elements of the maze.

```cpp
int play(vector<vector<int>> maze, int min, int max, int& steps);
```
There is a function named play that takes a maze, minimum and maximum values, and a reference to the number of steps as input. The function returns 1 if the player wins and 0 if the player loses.  
The play function follows the following structure:  
Initialization: The function initializes variables and displays instructions for playing the game.  
Game Loop: The function enters a loop that continues until one of the following conditions is met:  
The player runs out of steps.  
The player reaches the exit.  
The player is unable to make a valid move.  
User Input: Inside the game loop, the player is prompted to enter a move. The available moves are 'w' (up), 's' (down), 'a' (left), and 'd' (right).  
Move Validation: The function checks if the move is valid based on the current position of the player and the maze structure. If the move is valid, the player's position is updated, points are collected, and the maze is updated accordingly. If the move is invalid, an appropriate message is displayed.  
Game Status: After each move, the function displays the updated maze, the number of steps left, and the total points collected.  
Game Result: Once the game loop ends, the function checks the final game state. If the player has reached the exit with the correct number of points, a "Congratulations" message is displayed. Otherwise, a "You Lost" message is displayed.

```cpp
string choosmap();
```
The choosmap() function provides a convenient way for users to choose a map from a list of options stored in a text file.

```cpp
inline bool exists_test(const std::string& name);
```
Its a simple function called exists_test that takes a std::string parameter representing the file name. The function returns a boolean value indicating whether the file exists or not.

```cpp
vector<vector<int>> userfiletovec(string& mapname);
```
The userfiletovec function is a useful utility for reading the contents of a file into a 2D vector . It handles file existence checks, user input validation, and dynamic memory allocation.

```cpp
vector<vector<int>> filetovec(string mapname);
```
The function filetovec takes a string parameter mapname, which represents the name of the file to be read.  
The code checks if the file extension is ".txt" by extracting the last four characters of the mapname string using the substr function. If the extension is not ".txt", it appends ".txt" to the mapname string.  
The code opens the file using the ifstream class and assigns it to the file object.  
The dimensions of the map (number of rows and columns) are read from the file using the >> operator and stored in the row and col variables. The steps variable is also read but its purpose is not clear from the provided code snippet.  
A 2D array arr is dynamically allocated to store the map data. The size of the array is determined by the values of row1 and col1.  
The map data is read from the file into the arr array using nested loops.  
The arr array is then converted into a vector vec. Each element of the arr array is converted to an integer using the stoi function and pushed into the corresponding row of the vec vector.  
After converting the array into a vector, the dynamically allocated memory for the arr array is cleaned up to avoid memory leaks.
Finally, the vec vector is returned from the function.  

```cpp
int getstepsfromfile(string mapname);
```
We first check if the given mapname has a ".txt" extension. We do this by extracting the last four characters of the string using the substr function and comparing it with ".txt". If the extension is missing, we append ".txt" to the mapname string.  
Next, we create an ifstream object named file and open the file with the given mapname. This allows us to read data from the file.  
We then declare three string variables: row, col, and steps. These variables will store the values read from the file.  
Using the >> operator, we read the values from the file into the respective variables.  
Finally, we convert the steps string to an integer using the stoi function and return the result.  

```cpp
string get_localtime();
```
This is a function from the <ctime> library that converts the time_t object to a local time representation.

```cpp
userinfo getuserinfo(string name);
```
A function that retrieves user information from a file. It takes a username as input and returns a userinfo struct containing the user's information. If the user exists in the file, their information is read from the file. If the user does not exist, a new entry is created for them in the file with default values.

```cpp
void updateuserinfo(userinfo user, int gameresult, int playingtime);
```
We have a function called updateuserinfo that is responsible for updating user information in a CPP program. The function takes in three parameters: userinfo user, int gameresult, and int playingtime. The userinfo structure holds information about the user, such as their name, play count, win count, last win time, total playing time, and total playing time for wins.

```cpp
void printuserinfo(userinfo user);
```
In this code section, we have a function called printuserinfo that takes a userinfo object as a parameter. The purpose of this function is to print the information stored in the userinfo object.

```cpp
vector <history>  gethistory();
```
Here we have a function called gethistory() that retrieves historical data from a file and returns it as a vector of history objects. The history objects contain information about a player's name, the map they played on, the result of the game, the date of the game, and the playing time.

```cpp
void updatehistory(string playername, string mapname, int result, int playingtime, vector<history> historyvec);
```
It takes several parameters, including the player's name, map name, game result, playing time, and the game history vector then it start to the process of reading from or writing to files. In our code, we use file handling to store the updated game history in a text file named "history.txt".

```cpp
void showhistory(vector<history> vec);
```
This function calculate time and print history.

```cpp
void updatetopplayers(userinfo user);
```
This function updates the top players based on the provided user's information.

```cpp
  void showtopplayers();
```
The showtopplayers() function is responsible for displaying the leaderboard of the top players in a game. It reads the player data from a file called "topplayers.txt" and then prints the player's name, score, and playing time.

## FAQ

#### How to start gaming?

With using menu you can easily start you first try. Just press your chosen number on your keyboard and start your advanture :)

#### Why it dosent open the files?

If you find problem with opening files replace file names with full address of file on your system. 
like:

before:
```cpp
 ifstream usernamesfile("username.txt"); 
```
after:
```cpp
ifstream usernamesfile("C:\Users\A\Desktop\c++\...");
```

### Is there any diffrence between "macOS" and "Windows" or "Visual Stadio" and "VS Code" for running this code?
Actually nothing especially,but the best version of run is on windows. However we run this code on both. There are some little point that I mention if you find any problem try them.
- 1: change the name of file with full address.
- 2: comment second space_to_underline function and uncomment the other one which exist above that.
- 3: comment first get_localtime function and uncomment second one.
- 4: if your problem didnt solved, send me a message by using the link of my telegram acount in link box. =)
  




## 🔗 Links
https://t.me/lilia_rh  
https://t.me/mahsa_solimani


## Feedback

If you have any feedback, please reach out to us. <3 
## 
- [Liliarouhi](https://www.github.com/Liliarouhi)
- [Mahsesol](https://www.github.com/Mahsesol))

