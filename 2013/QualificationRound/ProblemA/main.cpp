#include <cstdio>

using namespace std;

/* Function Prototypes */
void readBoardData();
bool check(char c);
void processTestCase();


/* Global Variables */
int T;
char board[4][4];
bool emptyFields;


int main() {
    scanf("%d", &T);

    int t=0;
    while (t<T) {
        printf("Case #%d: ", ++t);
        processTestCase();
    }

    return 0;
}

void processTestCase() {
    emptyFields = false;
    readBoardData();

    if(check('X')){
        printf("X won\n");
        return;
    }
    if(check('O')){
        printf("O won\n");
        return;
    }
    
    if(emptyFields){
        printf("Game has not completed\n");
        return;
    }
    printf("Draw\n");

    return;
}


bool check(char c) {
    int joker = 'T';
    bool win = true;
        
    // find in left diagonal
    win = true;
    for (int i=0;i<4;i++ ) {
        for (int j=0;j<4;j++ ) {
            if(i==j & board[i][j] != c && board[i][j] != joker ){
                win = false;
            }
        }
    }
    if(win){
        return true;
    }

    // find in right diagonal
    win = true;
    for (int i=3;i>=0;i-- ) {
        for (int j=0;j<4;j++ ) {
            if( (i+j)==3 & board[i][j] != c && board[i][j] != joker ){
                win = false;
            }
        }
    }
    if(win){
        return true;
    }

    // find in rows
    for (int i=0;i<4;i++ ) {
        win = true;
        for (int j=0;j<4;j++ ) {
            if(board[i][j] != c && board[i][j] != joker ){
                win = false;
            }
        }
        if(win){
            return true;
        }
    }
    
    // find in columns
    for (int j=0;j<4;j++ ) {
        win = true;
        for (int i=0;i<4;i++ ) {
            if(board[i][j] != c && board[i][j] != joker ){
                win = false;
            }
        }
        if(win){
            return true;
        }
    }
    
    return false;
}

void readBoardData() {
    for (int i=0;i<4;i++ ) {
        for (int j=0;j<4;j++ ) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == '.'){
                emptyFields = true;
            }
        }
    }
}
