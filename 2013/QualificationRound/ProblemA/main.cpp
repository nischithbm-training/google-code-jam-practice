#include <iostream>
#include <string>

using namespace std;

/* Function Prototypes */
void readBoardData();
bool check(char c);
string processTestCase();


/* Global Variables */
int T;
char board[4][4];
bool isEmptyFields;


int main() {
    string tempStr;

    cin >> T;
    getline(cin,tempStr);
    
    for (int t=0;t<T;t++ ) {
        cout << "Case #" << t+1 << ": " << processTestCase() << endl;
        
      getline(cin,tempStr);
    }

    return 0;
}

string processTestCase() {
    isEmptyFields = false;
    readBoardData();

    if(check('X')){
        return "X won";
    }
    if(check('O')){
        return "O won";
    }
    
    if(isEmptyFields){
        return "Game has not completed";
    }

    return "Draw";
}


bool check(char c) {
    int joker = 'T';
    int counter = 0;
        
    // find in left diagonal
    counter = 0;
    for (int i=0;i<4;i++ ) {
        for (int j=0;j<4;j++ ) {
            if(i==j & (board[i][j] == c || board[i][j] == joker) ){
                counter++;
            }
        }
    }
    if(counter == 4){
        return true;
    }

    // find in right diagonal
    counter = 0;
    for (int i=3;i>=0;i-- ) {
        for (int j=0;j<4;j++ ) {
            if( (i+j)==3 & (board[i][j] == c || board[i][j] == joker) ){
                counter++;
            }
        }
    }
    if(counter == 4){
        return true;
    }

    // find in rows
    for (int i=0;i<4;i++ ) {
        counter = 0;
        for (int j=0;j<4;j++ ) {
            if(board[i][j] == c || board[i][j] == joker ){
                counter++;
            }
        }
        if(counter == 4){
            return true;
        }
    }
    
    // find in columns
    for (int j=0;j<4;j++ ) {
        counter = 0;
        for (int i=0;i<4;i++ ) {
            if(board[i][j] == c || board[i][j] == joker ){
                counter++;
            }
        }
        if(counter == 4){
            return true;
        }
    }
    
    return false;
}

void readBoardData() {
    for (int i=0;i<4;i++ ) {
        for (int j=0;j<4;j++ ) {
            cin >> board[i][j];
            if(board[i][j] == '.'){
                isEmptyFields = true;
            }
        }
    }
}
