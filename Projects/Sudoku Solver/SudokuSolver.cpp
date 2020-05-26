#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                     {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                     {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                     {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                     {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                     {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                     {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                     {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                     {0, 0, 5, 2, 0, 6, 3, 0, 0} };

bool valid(int board[9][9], int x, int y, int num){
    
    //check row
    for(int i = 0; i < 9; i++){
        if(board[x][i] == num){
            return false;
        }
    }

    //check column
    for(int i = 0; i < 9; i++){
        if(board[i][y] == num){
            return false;
        }
    }

    int tx = x - x%3;
    int ty = y - y%3;
    //check grid
    for(int i = tx; i < tx + 3; i++){
        for(int j = ty; j < ty + 3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }

    return true;
}

void printBoard(int board[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool findEmpty(int board[9][9], int& i, int& j){
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] == 0)
                return true;
        }
    }

    return false;
}

bool solve(int board[9][9]){
    int i, j;
    if(!findEmpty(board, i, j)){
        return true;
    }
    
    int num = 1;
    while(num < 10){
        if(valid(board, i, j, num)){
            board[i][j] = num;
            if(solve(board)){
                return true;
            }
            board[i][j] = 0;
        }

        num++;
    }

    return false;
    
}


int main(){
    printBoard(sudoku);
    cout<<endl;
    cout<<endl;
    if(solve(sudoku))
        printBoard(sudoku);
    else
        cout<<"No solution exist";

    cin.get();
    return 0;
}