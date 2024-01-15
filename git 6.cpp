bool check_number(string str) {
    if(str[0]=='-'){
        for (int i = 1; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;}
    else{
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;    }
}