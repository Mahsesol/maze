# Maze
[![AGPL License](https://img.shields.io/badge/IUST-Mathemati%20c:-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)

An enjoyable funny exercise for your mind.
Here is a 2D maze of number project which is improving your creativity, problem solving skills, memory, hand-eye coordination and... .Beside all its a good hobby for your free times!


![Screenshot (5)](https://github.com/Mahsesol/maze/assets/154425249/887643dd-1162-45d7-8c9d-b51c7a12d8f4)



## Explanation
  When you play this game at first you see a menu which guid you to chose a number, then you should share your chosen number with maze by clicking on that on your keyboard.  
  Number "1" is going to make a maze table az your taste. It include two parts hard one and easy one.  
Number "2" is guiding you to playground. you can start plaing here.  
Number "3" is related to maze solutions.  
With using number "4" you can see users informations such as name, play count, win count, last win date and time spent on playing.  
"5" is  history and "6" is leader board by using each ones number you are able to see three top players in leader board and some information like players name, 
maps name, result,... of ten last game in history part.  
And last choice, number "7" is using to exsiting from code.  
If you are curious about details of the action behind each number and function, after checking codes, check "functions" part here.  



## Features

- You are able to see the history of game.
- You can see leader board.
- There are each maze solution.
- You can design your own play ground.
- You are able to see each plays time spent and campare with your previos record.
- You can personalize your table of number(playground).
- you are able to chose a map or user name more than one word.



## 🛠 Functions
```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

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
Using the >> operator, we read the values from the file into the respective variables. The >> operator is used to extract data from the file stream.
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

## Q&A

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

### Is there any diffrence between "IOS" and "Windows" or "Visual Stadio" and "VS Code" for running this code?
Actually nothing especially,but the best version of run is on windows. we run this code on both. There are some little point that I mention if you find any problem try them.
- 1: change the name of file with full address.
- 2: comment second space_to_underline function and uncomment the other one exist above that.
- 3: comment first get_localtime function and uncomment second one
- 4: if your problem didnt solved, send me a message by using the link of my telegram acount in link box. =)
  




## 🔗 Links
https://t.me/lilia_rh  
https://t.me/mahsa_solimani


## Feedback

If you have any feedback, please reach out to us. <3 
## 
- [Liliarouhi](https://www.github.com/octokatherine)
- [Mahsesol](https://www.github.com/octokatherine)

