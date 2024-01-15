vector<vector<int>> hardmazemaker( int& step){
random_device rd;
mt19937 g(rd());

    string checkrow , checkcol;
    int row,col;
    cout<<"Enter the size of your maze"<<endl<<"rows: ";
    try{
    cin>>checkrow;
    if(check_number(checkrow)==0 || stoi(checkrow)<=1){
        throw checkrow;
        }
    }catch(...){
        while( check_number(checkrow)==0 || stoi(checkrow)<=1){
            cout<<"Please enter the number of rows correctly"<<endl<<"The number of rows must be a digit greater than 1"<<endl<<"rows: ";
            cin>>checkrow;
        }
    }
    row=stoi(checkrow);
    cout<<"columns:";
    try{
    cin>>checkcol;
    if(check_number(checkcol)==0 || stoi(checkcol)<=1){
        throw checkcol;
        }
    }catch(...){
        while(check_number(checkcol)==0 || stoi(checkcol)<=1){
            cout<<"Please enter the number of columns correctly"<<endl<<"The number of columns must be a digit greater than 1"<<endl<<"columns: ";
            cin>>checkcol;
        }
    }
    col=stoi(checkcol);
    
int sum=0;
    string checkmin , checkmax;
    int min,max;
    cout<<"Enter the minimum and maximum of your maze"<<endl<<"min: ";
    try{
    cin>>checkmin;
    if(check_number(checkmin)==0){
        throw checkmin;
        }
    }catch(...){
        while(check_number(checkmin)==0){
            cout<<"The minimum of your maze should be a number" <<endl<<"min: ";
            cin>>checkmin;
        }
    }
    min=stoi(checkmin);
    
    cout<<"max:";
    try{
    cin>>checkmax;
    if(check_number(checkmax)==0){
        throw checkmax;
        }
    }catch(...){
        while(check_number(checkmax)==0){
            cout<<"The maximum of your maze should be a number"<<endl <<"max: ";
            cin>>max;
        }
    }
    max=stoi(checkmax);


    

vector<vector<int>> arr(row,vector<int>(col));




for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        arr[i][j]=SPECIAL_VALUE;
    }
}
    
    string checksteps;

    cout<<"Enter the steps of your path: ";
    try{
    cin>>checksteps;
    if(check_number(checksteps)==0 || stoi(checksteps)<0 ){
        throw checkmin;
        }
    }catch(...){
        while(check_number(checksteps)==0|| stoi(checksteps)<0 ){
            cout<<"Steps of you path should be a posetive number" <<endl<<"steps: ";
            cin>>checksteps;
        }
    }
    step=stoi(checksteps);

    if(!generatePath(arr,0,0,row-1,col-1,step)){
        cout<<"There is no path with this number of steps"<<endl;
        while(!generatePath(arr,0,0,row-1,col-1,step)){
            cout<<"Enter the steps of your path: ";
            try{
            cin>>checksteps;
            if(check_number(checksteps)==0 || stoi(checksteps)<0 ){
                throw checkmin;
                }
            }catch(...){
                while(check_number(checksteps)==0|| stoi(checksteps)<0 ){
                    cout<<"Steps of you path should be a posetive number" <<endl<<"steps: ";
                    cin>>checksteps;
                }
            }
            step=stoi(checksteps);
        }
            
            }
    
    
    
string checkbmin , checkbmax;
int blockmin,blockmax;
    cout<<"Enter the minimum and maximum number of the blocks in your maze"<<endl<<"minimum number of blocks: ";
    try{
    cin>>checkbmin;
    if(check_number(checkbmin)==0 || stoi(checkbmin)<0){
        throw checkbmin;
        }
    }catch(...){
        while(check_number(checkbmin)==0 || stoi(checkbmin)<0){
            cout<<"The minimum number of blocks must be a posetive number" <<endl<<"minimum number of blocks: ";
            cin>>checkbmin;
        }
    }
    blockmin=stoi(checkbmin);
    
    cout<<"maximum number of blocks:";
    try{
    cin>>checkbmax;
    if(check_number(checkbmax)==0  stoi(checkbmax)<blockmin  stoi(checkbmax)>row*col-step){
        throw checkbmax;
        }
    }catch(...){
        if(check_number(checkbmax)==0  stoi(checkbmax)<blockmin){        while(check_number(checkbmax)==0  stoi(checkbmax)<min){
    cout<<"The maximum number of blocks must be a posetive number greater than minimum number of blocks" <<endl<<"maximum number of blocks: ";
            cin>>checkbmax;
        }}else{
            while(stoi(checkbmax)>row*col-step){
                cout<<"Too many blocks for your path!" <<endl<<"maximum number of blocks: ";
                cin>>checkbmax;      }  }
    }
    blockmax=stoi(checkbmax);
    




uniform_int_distribution<int> distribution(min,max);
uniform_int_distribution<int> distribution1(blockmin,blockmax);
sum=0;

int val=0;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(i==row-1&&j==col-1){
            break;
        }
        if(arr[i][j]==0){
            val=distribution(g);
    while (val==0){
        val=distribution(g);
    }
    arr[i][j]=val;
    sum+=val;
     while(((i==row-2&&j==col-2)||(i==row-1&&j==row-2)||(j==col-1&&i==row-2))&&sum==0){
        sum-=val;
        val=distribution(g);
    while (val==0){
        val=distribution(g);
    }
    arr[i][j]=val;
    sum+=val;

    }

        }
   

    }
}




arr[row-1][col-1]=0;
blockmaker(arr,distribution1(g));
arr[row-1][col-1]=sum;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(arr[i][j]==SPECIAL_VALUE &&((i!=row-1)||(j!=col-1))){
             val=distribution(g);
    while (val==0){
        val=distribution(g);
    }
    arr[i][j]=val;
        }
            
        
       }
    
  
}

    return arr;
}
