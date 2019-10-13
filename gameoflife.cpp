#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

#define ALIVE 'O';
#define DEAD ' ';
#define CANCER 'X';
#define TESTING "TEST";

class Board
{
private:
    int row;
    int col;
    char board[20][75];
    int _time;
    char currentcell;
    int numberofcells;


public:

    Board();
    Board(int x_in, int y_in);
    
    void initialboard(char board[20][75]);
    void seed_cells(int selection,int con);
    void choose_cells(int selection);
    void display();
    void nextstate();
    void set_time(int time_in);
    void get_time();
    void num_of_cells(int num);
    void  get_num_cell();

    void setCell(int select);
};

void Board:: initialboard(char board[20][75])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            board[i][j]=DEAD;
        }
    }
}

Board::Board()
{
    row=0;
    col=0;
    _time=0;
    initialboard(board);
}

Board::Board(int x_in, int y_in)
{
    row=x_in;
    col=y_in;
    _time=0;
    initialboard(board);
}

void Board:: setCell(int select)
{
    if(select==1)
    {
        currentcell=ALIVE;
    }
    if(select==2)
    {
        currentcell=CANCER;
    }
    
}

void Board:: seed_cells(int selection, int con)
{
    int cells_need=(20*75*con)/100;
    int cell_gen=0;
    
    setCell(selection);
    
    srand (static_cast<unsigned int> (time(NULL)));
    
    while(cell_gen!=cells_need)
    {
        bool generated=false;
    
        while(!generated)
        {
            int rand_row=rand()%row;
            int rand_col=rand()%col;
            
            board[rand_row][rand_col]=currentcell;
            generated=true;
            ++cell_gen;
        }
    }

    num_of_cells(cells_need);
}

void Board:: choose_cells(int selection)
{
   
    setCell(selection);
    
    for(int i=7; i<10; i++)
    {
        for(int j=35; j<40; j++)
        {
            board[i][j]=currentcell;
        }
    }

}







void Board:: nextstate()
{
    
    int neighbours=0;
    cout<<endl;
    set_time(_time);
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(board[i][j+1]==currentcell)
            {
               neighbours++;
            }
            if(board[i][j-1]==currentcell)
            {
                neighbours++;
            }
            if(board[i-1][j]==currentcell)
            {
                neighbours++;
            }
            if(board[i+1][j]==currentcell)
            {
                neighbours++;
            }
            if(board[i-1][j-1]==currentcell)
            {
                neighbours++;
            }
            if(board[i-1][j+1]==currentcell)
            {
                neighbours++;
            }
            if(board[i+1][j-1]==currentcell)
            {
                neighbours++;
            }
            if(board[i+1][j+1]==currentcell)
            {
                neighbours++;
            }
       
            if(currentcell=='O')
            {
                if(board[i][j]==currentcell && neighbours>=4)
                {
                        board[i][j]=DEAD;
                }
                else if(board[i][j]==currentcell && neighbours<=1)
                {
                    board[i][j]=DEAD;
                }
                else if(board[i][j]==' ' && neighbours==2 )
                {
                    board[i][j]=currentcell;
                }
            }
            else
            {
                if(board[i][j]==currentcell && neighbours>=5)
                {
                    TESTING;
                    board[i][j]=DEAD;
                }
                else if(board[i][j]==currentcell && neighbours<2)
                {
                    board[i][j]=DEAD;
                }
                else if(board[i][j]==' ' && neighbours==2)
                {
                    board[i][j]=currentcell;
                }
            }
                
            neighbours=0;
        }
    }

    int num_cells=0;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(board[i][j]==currentcell)
            {
                num_cells++;
            }
        }
    }
    
    num_of_cells(num_cells);
    ++_time;
    
}

void Board:: display()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cout<<board[i][j];
        }
    }
    
    cout<<endl;
}

void Board:: set_time(int time_in)
{
    _time=time_in;
}

void Board:: get_time()
{
    cout<<"Time: "<<_time<<endl;
}

void Board:: num_of_cells(int num)
{
    numberofcells=num;
}

void Board:: get_num_cell()
{
    cout<<"Number of cells: "<<numberofcells<<endl;
}




int main()
{
    Board board(20,75);
    int confluence=0,selection=0,seed=0;
    char c=' ';
    
    cout<<"***** Welcome to cell simulator *****"<<endl;
    
    cout<<"1) Random cells 2) Place cell in center : ";
    cin>>seed;
    cout<<"Enter 1) Normal cell or 2) Cancer cell : ";
    cin>>selection;
    cout<<"Enter the confluence in %: ";
    cin>>confluence;
    
    cout<<endl;
    
    if(seed==1)
        board.seed_cells(selection,confluence);
    else if(seed==2)
        board.choose_cells(selection);
    system("clear");
    
    using namespace this_thread;
    using namespace chrono;

    while(c!='q')
    {
        system("clear");
        board.display();
        board.get_time();
        board.get_num_cell();
        
        //c = cin.get();
        sleep_until(system_clock::now() + milliseconds(200));
        board.nextstate();
        

    }
}
