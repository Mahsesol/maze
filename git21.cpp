
    else if (choice == "4") {
    userinfo:
        userinfo thisuserinfo = getuserinfo(username);
        cout << endl << "Here you are: " << endl;
        cout << endl << "\u001b[36;1m*******YOUR USER INFORMATION********\u001b[0m" << endl;
        printuserinfo(thisuserinfo);
        cout << endl << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;

    }

    else if (choice == "5") {
    his:
        vector <history> historyvec = gethistory();
        cout << endl << "Here you are: " << endl;
        showhistory(historyvec);
        cout << endl << endl << "Going back to menu..." << endl;
        goto menu;
    }

    else if (choice == "6") {
    tops:
        showtopplayers();
        cout << endl << endl << endl << "Going back to menu..." << endl;
        cout << endl;
        goto menu;
    }

    else if (choice == "7") {
        return 0;
    }


    return 0;
}


