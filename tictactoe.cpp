#include <iostream>

using namespace std;

class TicTacToe
{
    
public:
    TicTacToe();
    
    void iniBoard(char board[3][3]);
    void printBoard(char board[3][3]);
    void playgame();
    
    int getRow();
    int getCol();
    bool move(int x, int y, char currentplayer);
    bool victory(char currentplayer);
    

private:
    char board[3][3];
};

TicTacToe::TicTacToe()
{
    iniBoard(board);
}

void TicTacToe:: iniBoard(char board[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]=' ';
        }
    }
}

void TicTacToe:: printBoard(char board[3][3])
{
    cout<<" |1|2|3|"<<endl;
    for(int i=0; i<3; i++)
    {
        cout<<"---------"<<endl;
        cout<<i+1;
        for( int j=0; j<3; j++)
        {
            cout<<'|'<<board[i][j];
        }
        cout<<'|'<<endl;
    }
}

int TicTacToe:: getRow()
{
    int row=0;
    bool validmove=true;
    
    while(validmove==true)
    {    cout<<"Enter row: ";
        cin>>row;
    
        if(row<1 || row>3)
        {
            cout<<"Enter valid move!"<<endl;
            validmove=true;
        }
        else
            validmove=false;
    }
    return row-1;
}

int TicTacToe:: getCol()
{
    int col=0;
    bool validmove=true;
    
    while(validmove==true)
    {    cout<<"Enter col: ";
        cin>>col;
        
        if(col<1 || col>3)
        {
            cout<<"Enter valid move!"<<endl;
            validmove=true;
        }
        else
            validmove=false;
    }
    return col-1;
}

bool TicTacToe:: move(int x, int y, char currentplayer)
{
    if(board[x][y]!=' ')
        return false;
    board[x][y]=currentplayer;
    return true;
}


bool TicTacToe:: victory(char currentplayer)
{
   if( (board[0][0]==currentplayer) && (board[0][0]==board[1][0]) && board[1][0]==board[2][0]) //row 1
       return true;
   else if( (board[0][0]==currentplayer) && (board[0][0]==board[0][1]) && board[0][1]==board[0][2]) //col 1
        return true;
   else if( (board[1][0]==currentplayer) && (board[1][0]==board[1][1]) && board[1][1]==board[1][2]) //col 2
       return true;
   else if( (board[2][0]==currentplayer) && (board[2][0]==board[2][1]) && board[2][1]==board[2][2]) //col 3
       return true;
   else if( (board[0][1]==currentplayer) && (board[0][1]==board[1][1]) && board[1][1]==board[2][1]) //row2
       return true;
   else if( (board[0][2]==currentplayer) && (board[0][2]==board[1][2]) && board[1][2]==board[2][2]) //row3
       return true;
   else if( (board[0][0]==currentplayer) && (board[0][0]==board[1][1]) && board[1][1]==board[2][2]) //dia 1
       return true;
   else if( (board[2][0]==currentplayer) && (board[2][0]==board[1][1]) && board[1][1]==board[0][2]) //dia 2
        return true;
    
    return false;
    
}





void TicTacToe:: playgame()
{
    int row=0, col=0,count=0;
    char player1='X', player2='O',multiplayer;
    bool gameOver=false;
   
    
    cout<<"******Welcome to the game of Tic-Tac-Toe!*******"<<endl;
    
    cout<<"Multiplayer? y/n : ";
    cin>>multiplayer;
  
    
    char currentplayer=player1;
    printBoard(board);

    
    while(!gameOver)
    {
        cout<<"Player "<<currentplayer<<" is playing."<<endl;
       row= getRow();
       col= getCol();
        
       if(move(row, col, currentplayer)==false)
       {
           cout<<"Spot taken. Try again."<<endl;
       }
       else
       {
           count++;
           
           if(victory(currentplayer)==true)
           {
               cout<<"The winner is player "<<currentplayer<<"!!!"<<endl;
               cout<<"Game Over!"<<endl;
               gameOver=true;
           }
           else if (count==9)
           {
               cout<<"Game is a tie! :("<<endl;
               gameOver=true;
           }
           
        if(currentplayer==player1)
        {
            currentplayer=player2;
        }
        else
            currentplayer=player1;
       }
        printBoard(board);
    }
}

int main()
{
    TicTacToe game;
    game.playgame();
}
