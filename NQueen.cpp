#include<iostream>
using namespace std;

bool isValidMove(int newRow, int newCol, int size, bool *board){
	bool valid = true;
	for(int i=0; i<size; i++){
		if(board[i*size+newCol]){
			valid = false;
		}
	}
	for(int i=newRow,j=newCol; i>=0 && j>=0; i--,j--){
		if(board[i*size+j]){
			valid = false;
		}
	}
	for(int i=newRow, j=newCol; i>=0 && j<size; i--,j++){
		if(board[i*size+j]){
			valid = false;
		}
	}
	return valid;
}


bool nqueen(int row, int size, bool *board){
	if(row == size-1){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout<<board[i*size+j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	else{
		for(int col=0; col<size; col++){
			int newRow = row + 1;
			if(isValidMove(newRow,col,size,board)){
				board[newRow*size+col] = true;
				if(nqueen(newRow,size,board)){
					return true;
				}
				board[newRow*size+col] = false;
			}
		}
		return false;
	}
}



int main() {
	bool b[][4] = {
		{false,false,false,false},
		{false,false,false,false},
		{false,false,false,false},
		{false,false,false,false}
	};
	nqueen(-1,4,&b[0][0]);
	return 0;
}