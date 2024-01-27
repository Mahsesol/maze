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

```

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

