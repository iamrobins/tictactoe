#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

char board[3][7]; 



// void Winner(){
//     if (board[0][1]==1 && board[1]){
//       cout<<"You are the Winner"<<endl;
//       exit(1);  
//     }
// }

void display(){
    int rows, columns;
//********************For Player***********************
    int n=9;
    while(n-- > 0)
    {
    int x,y;
    cin>>x;
    x = (x == 1) ? 0 : x;
    x = (x == 2) ? 1 : x;
    x = (x == 3) ? 2 : x;
    cin>>y;
    y = (y == 3) ? 5 : y;
    y = (y == 0) ? 1 : y;
    y = (y == 2) ? 3 : y;
    

        for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 1 ; columns < 7 ; columns = columns+2 ){

            board[ x ][ y ] = 'X';
        }
    }

        for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 7 ; columns++ )
            {
            cout<< board[rows][columns] ; 
            }
            cout<<"\n";
        }
        cout<<"\n";


//***********************For CPU****************************

    srand(time(NULL));
    int randX = (rand() % 3) + 1;

    //To check randX and player x should not be same
    while(randX==x){
        randX = (rand() % 3) + 1;
    }

    randX = (randX == 1) ? 0 : randX;
    randX = (randX == 2) ? 1 : randX;
    randX = (randX == 3) ? 2 : randX;
    

    int randY = (rand() % 3) + 1;
    //To check randY and player y should not be same
    while(randY==y){
        randY = (rand() % 3) + 1;
    }
    randY = (randY == 3) ? 5 : randY;
    randY = (randY == 0) ? 1 : randY;
    randY = (randY == 2) ? 3 : randY;


    for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 1 ; columns < 7 ; columns = columns+2 ){

            board[ randX ][ randY ] = 'O';
        }
    }

        for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 7 ; columns++ )
            {
            cout<< board[rows][columns] ; 
            }
            cout<<"\n";
        }
        
/*Check Winning*/
   // All Column Winning Cases
    if((board[0][1]=='X') && (board[1][1]=='X') && (board[2][1]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else if((board[0][3]=='X') && (board[1][3]=='X') && (board[2][3]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else if((board[0][5]=='X') && (board[1][5]=='X') && (board[2][5]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }

   // All Row Winning Cases
    else if((board[0][1]=='X') && (board[0][3]=='X') && (board[0][5]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else if((board[1][1]=='X') && (board[1][3]=='X') && (board[1][5]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else if((board[2][1]=='X') && (board[2][3]=='X') && (board[2][5]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }

   // All Diagnal Winning Cases
    else if((board[0][1]=='X') && (board[1][3]=='X') && (board[2][5]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else if((board[0][5]=='X') && (board[1][3]=='X') && (board[2][1]=='X')){
        cout<<"You won the game"<<endl;
        break;
        }
    else
        continue;
    }
    
}/*End of function display()*/

void drawBoard()
{
 
    int rows, columns;


    for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 0 ; columns < 7 ; columns=columns+2 ){ // to fill every second elemnt of the array .. just increment the counter by 2

            board[ rows ][ columns ] = '|';
        }
    }

    for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 1 ; columns < 7 ; columns = columns+2 ){

            board[ rows ][ columns ] = ' ';
        }
    }

    for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 7 ; columns++ )
            {
            cout<< board[rows][columns] ; 
            }
            cout<<"\n";
        }
    display();
    

}/* end function drawboard */

int main()
{
    drawBoard();
    return 0;
}





















































































/*
#include <iostream>
using namespace std;

char board[3][7], XO; // you were declaring your array wrong .. it rows in first bracket and columns in 2nd bracket

void input(){

    int x,y;
    cin>>x;
    cin>>y;

    int rows, columns;

        for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 1 ; columns < 7 ; columns = columns+2 ){

            board[ rows ][ columns ] = 'R';
        }
    }

        for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 7 ; columns++ )
            {
            cout<< board[rows][columns] ; // its supposed to be %c as you are printing a character
            }
            cout<<"\n";
        }
    
}

void drawBoard()
{
    int n;
    cin >> n;
    while(n!=2){
 
    int rows, columns;


    for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 0 ; columns < 7 ; columns=columns+2 ){ // to fill every second elemnt of the array .. just increment the counter by 2

            board[ rows ][ columns ] = '|';
        }
    }

    for ( rows = 0 ; rows < 3 ; rows++ ){
        for ( columns = 1 ; columns < 7 ; columns = columns+2 ){

            board[ rows ][ columns ] = ' ';
        }
    }

    for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 7 ; columns++ )
            {
            cout<< board[rows][columns] ; // its supposed to be %c as you are printing a character
            }
            cout<<"\n";
        }
    input();
    cin >> n;
    }

}



int main()
{
    drawBoard();
    return 0;
}
*/