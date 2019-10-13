#include <iostream>
#include <vector>

using namespace std;
 
// printBoard
void printBoard(vector<vector<char> > board)
{
    cout<< "  1 2 3 4 5 6 " << endl ;
    for (int i = 0; i < 6; i++)
    {
        cout << "--------------\n" << char('a' + i);
        for (int j = 0; j < 6; j++)
            cout << "|" << board[i][j];
        cout << "|\n";
    }
    cout << "--------------" << endl;
   
}
 
 
/*
 * @return bool: whether row & col is within board;
 */

bool withinBoard(const int& r, const int& c)
{
    return (r >= 0 && r <= 5 && c >= 0 && c <= 5);
}
 
/*
 * Direction:
 * 0 : top left
 * 1 : top
 * 2 : top right
 * 3 : right
 * 4 : so forth, clockwise until 7.
 *
 * @param r: row, at end will change to shifted direction
 * @param c: col, at end will change to shifted direction
 * @param direction: direction as explained above
 * @return bool: whether is within board or not
 */

bool nextCoord(int& r, int& c, const int& direction)
{
    switch (direction) {
        case (0):
            r--;
            c--;
            break;
        case (1):
            r--;
            break;
        case (2):
            r--;
            c++;
            break;
        case (3):
            c++;
            break;
        case (4):
            r++;
            c++;
            break;
        case (5):
            r++;
            break;
        case (6):
            r++;
            c--;
            break;
        case (7):
            c--;
            break;
    }
    return withinBoard(r, c);
}


/*
 * get in nextMoves a vector of possible nextMoves
 */

 
void getNextValidMoves(const vector<vector<char> >& board, const bool& Oturn, vector<pair<int, int> >& nextMoves)
{
    char player = 'X';
    char oppo = 'O';
    if (Oturn) {
        player = 'O';
        oppo = 'X';
    }
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            // debug << "CURRENT R C: " << r << " " << c << endl;
            if (board[r][c] != ' ') continue;
            else {
                bool validMove = false;
               
                for (int dir = 0; dir < 8 && !validMove; dir++) {
                    int currR = r, currC = c;
                    bool hasOppo = false;
                    while (nextCoord(currR, currC, dir) && board[currR][currC] == oppo) {
                        hasOppo = true;
                        // debug << "oppo found at " << currR << " " << currC << endl;
                        // debug << "tracked from " << r << " " << c << " " << dir << endl;
                    }
                    if (hasOppo && withinBoard(currR, currC) && board[currR][currC] == player) {
                        validMove = true;
                        // debug << "player found at " << currR << " " << currC << endl;
                        // debug << "tracked from " << r << " " << c << " " << dir << endl;
                        nextMoves.push_back(make_pair(r, c));
                    }
                }
            }
        }
    }
}


/*
 * Return true if current move within nextMoves
 */


bool isInNextMoves(const int& r, const int& c, const vector<pair<int, int> >& nextMoves)
{
    for (int i = 0; i < nextMoves.size(); i++) {
        int vR = nextMoves[i].first;
        int vC = nextMoves[i].second;
        if (vR == r && vC == c) return true;
    }
    return false;
}

 
/*
 * Make move, alter board
 */



void makeMove(const int& r, const int& c, const bool& Oturn, vector<vector<char> >& board)
{
    char player = 'X';
    char oppo = 'O';
    if (Oturn) {
        player = 'O';
        oppo = 'X';
    }
    board[r][c] = player;
    for (int dir = 0; dir < 8; dir++) {
        vector<vector<char> > lastState = board;
        int currR = r, currC = c;
       
        bool hasOppo = false;
       
        while (nextCoord(currR, currC, dir) && board[currR][currC] == oppo) {
            hasOppo = true;
            board[currR][currC] = player;
        }
       
        if (hasOppo) {
            if (withinBoard(currR, currC) && board[currR][currC] == player) {
                // valid move, don't restore
            }
            else {
                // invalid move! restore
                board = lastState;
            }
        }
    }
}
 
// convert user input into r & c
// return false if invalid input


bool inputToRC(const string& input, int& r, int& c)
{
    if (input.length() != 2) {
        return false;
    }
    char r_ch = input[0];
    char c_ch = input[1];
    if (r_ch < 'a' || r_ch > 'h' || c_ch < '0' || c_ch > '6')
    {
        cout << "Input out of board range!" << endl;
        return false;
    }
   
    r = r_ch - 'a';
    c = c_ch - '1';
   
    return true;
}


void calculateScore(const vector<vector<char> >& board, int& OScore, int& XScore)
{
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            char ch = board[r][c];
            if (ch == 'O') OScore++;
            else if (ch == 'X') XScore++;
        }
    }
}


int main()
{
    bool Oturn = true;
    int OScore = 0;
    int XScore = 0;
   
    vector<vector<char> > board(6, vector<char>(6, ' '));
   
    // initial moves
    board[2][2] = 'X';
    board[3][3] = 'X';
    board[2][3] = 'O';
    board[3][2] = 'O';
   
    vector<pair<int, int> > nextOMoves; // vector of pairs of r, c, for next valid O moves;
    vector<pair<int, int> > nextXMoves;
   
    getNextValidMoves(board, Oturn, nextOMoves);
   
    cout << "===== Welcome to vv3917's Othello Game! =====" << endl;
   
    // Othello: if Player 1 has no move, pass on to Player 2, if no valid moves for both, GAME OVER
    
    while (nextOMoves.size() || nextXMoves.size()) {
        printBoard(board);
       
        int inR = -1, inC = -1; // default to always fail isInNextMoves
        string inMove = ""; // default to always fail inputToRC
       
        if (Oturn) {
           
            // if O has no moves, pass to X
            if (nextOMoves.size() == 0)
            {
                cout << "Player O has no valid move! Passing on to Player X!" << endl;
                Oturn = false;
                nextXMoves.clear();
                getNextValidMoves(board, Oturn, nextXMoves);
                continue;
            }
           
            bool firstTry = true; // alert user of invalid move
           
            while (!inputToRC(inMove, inR, inC) || !isInNextMoves(inR, inC, nextOMoves))
            {
                if (!firstTry) {
                    cout << "Invalid move! Try again!" << endl;
                }
                cout << "Player O's turn, input move" << endl;
                cin >> inMove;
                firstTry = false;
            }
           
            makeMove(inR, inC, Oturn, board);
            Oturn = false;
            nextXMoves.clear();
            getNextValidMoves(board, Oturn, nextXMoves);
        }
       
        else
        {
            // player X's turn
            // if O has no moves, pass to X
            if (nextXMoves.size() == 0)
            {
                cout << "Player X has no valid move! Passing on to Player O!" << endl;
                Oturn = true;
                nextOMoves.clear();
                getNextValidMoves(board, Oturn, nextOMoves);
                continue;
            }
           
           
            bool firstTry = true; // alert user of invalid move
           
            while (!inputToRC(inMove, inR, inC) || !isInNextMoves(inR, inC, nextXMoves)) {
                if (!firstTry) {
                    cout << "Invalid move! Try again!" << endl;
                }
                cout << "Player X's turn, input move" << endl;
                cin >> inMove;
                firstTry = false;
            }
           
            makeMove(inR, inC, Oturn, board);
            Oturn = true;
            nextOMoves.clear();
            getNextValidMoves(board, Oturn, nextOMoves);
        }
    }
    cout << endl;
    cout << "GAME OVER!" << endl;
    calculateScore(board, OScore, XScore);
    char winner = (OScore > XScore) ? 'O' : 'X';
    cout << winner << " wins!" << endl;
    cout << "Score: O: " << OScore << " X: " << XScore << endl;
   
    return 0;
}
