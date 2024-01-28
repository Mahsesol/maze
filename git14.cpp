
//struct to save the top players information
struct topplayer {
    string name;
    int wincount;
    time_t playingtime;
};


//function to update top players after every game and save to a file
void updatetopplayers(userinfo user) {
    string wincount, winplayingtime;
    topplayer thisuser;
    thisuser.name = user.name;
    thisuser.wincount = user.wincount;
    thisuser.playingtime = user.winplayingtime;
    ifstream topplayerfile("topplayers.txt");
    topplayer tops[4];
    topplayer tmptops[3];
    int check = 0;

    for (int i = 0; i < 3; i++) {
        getline(topplayerfile, tops[i].name);
        getline(topplayerfile, wincount);
        getline(topplayerfile, winplayingtime);
        tops[i].wincount = stoi(wincount);
        tops[i].playingtime = stoi(winplayingtime);
        tmptops[i] = tops[i];
    }
    for (int i = 0; i < 3; i++) {
        if (thisuser.name == tops[i].name) {
            check++;
            break;

        }
    }

    topplayerfile.close();
    if (check == 0) {
        for (int i = 0; i < 3; i++) {


            if (thisuser.wincount >= tops[i].wincount) {
                if (thisuser.wincount > tops[i].wincount) {
                    auto buffer = tops[i];
                    tops[i] = thisuser;
                    tops[i + 1] = buffer;

                    break;
                }

                if (thisuser.wincount == tops[i].wincount) {
                    if (thisuser.playingtime < tops[i].playingtime) {
                        auto buffer = tops[i];
                        tops[i] = thisuser;
                        tops[i + 1] = buffer;
                        break;
                    }
                }
            }


        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (tops[i].name == thisuser.name) {
                int tartib = i;
                tops[i] = thisuser;
                for (int j = i - 1; j >= 0; j--) {
                    if (tops[tartib].wincount >= tops[j].wincount) {
                        if (tops[tartib].wincount > tops[j].wincount) {
                            auto buffer = tops[j];
                            tops[j] = tops[tartib];
                            tops[j + 1] = buffer;
                            tartib--;
                        }
                    }
                }
            }

        }
    }
    ofstream newtops("topplayers.txt");
    for (int i = 0; i < 3; i++) {
        newtops << tops[i].name << "\n" << tops[i].wincount << "\n" << tops[i].playingtime << "\n";
    }
    // int check1 = 0;
    // for (int i = 0; i < 3; i++) {
      //   if (tops[i].name != tmptops[i].name) {
      //       check1++;
           //  break;
      //   }
    // }
    // check1 = 0;
    // return check1;
}

