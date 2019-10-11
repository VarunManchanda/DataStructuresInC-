#include <iostream>
using namespace std;

bool canPlace(int board[9][9], int n, int row, int col, int theNumber){
	if(board[row][col]!=0){
		return false;
	}
	for(int i=0; i<n; i++){
		if(board[row][i]==theNumber) return false;
		if(board[i][col]==theNumber) return false;
	}
	int root = 3;
	int r = row - row%root;
	int c = col - col%root;
	for(int i=r; i<r+root; i++){
		for(int j=c; j<c+root; j++){
			if(board[i][j]==theNumber){
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int board[9][9], int n, int row, int col){
	if(row==n){
		return true;
	}
	if(col==n){
		return solveSudoku(board,n,row+1,0);
	}
	if(board[row][col]!=0){
		return solveSudoku(board,n,row,col+1);
	}
	for(int i=1; i<=n; i++){
		if(canPlace(board,n,row,col,i)==true){
			board[row][col] = i;
			bool success = solveSudoku(board,n,row,col+1);
			if(success==true){
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

void print(int board[9][9]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int n = 9;
	int board[9][9] = {
		{0, 4, 6, 0, 0, 5, 7, 0, 0},
        {0, 0, 0, 9, 0, 0, 0, 0, 0},
        {0, 9, 0, 0, 0, 1, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 3, 0, 1, 0, 0, 0, 0, 0},
        {4, 0, 0, 5, 2, 0, 0, 0, 8},
        {0, 8, 0, 0, 0, 0, 0, 7, 0},
        {5, 7, 0, 3, 0, 0, 0, 8, 2},
        {2, 0, 0, 0, 0, 0, 3, 0, 0}
	};
	bool success = solveSudoku(board,9,0,0);
	if(success){
		print(board);
	}
	else{
		cout<<"Not solvable"<<endl;
	}
	return 0;
}