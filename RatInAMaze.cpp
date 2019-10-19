#include <iostream>
using namespace std;


int row[] = {0,1,-1,0};
int col[] = {1,0,0,-1};

bool path(char a[][3], char sol[][3], int si, int sj)
{
	if(si<0 || si>=3 || sj<0 || sj>=3 || a[si][sj]=='x' || a[si][sj]=='r')
	{
		return false;
	}
	return true;
}

bool findPath(char b[][3], char sol[][3], int si, int sj, int fi, int fj, int &moves)
{
	if(si==fi && sj==fj)
	{
	    b[si][sj] = 'r';
		return true;
	}
	
	for(int i=0; i<4; i++){
		int newI = si + row[i];
		int newJ = sj + col[i];
		if(path(b,sol,newI,newJ))
		{
			b[si][sj] = 'r';
			if(findPath(b,sol,newI,newJ,fi,fj,moves)){
			    moves++;
				return true;
			}
			b[si][sj] = '.';
			moves--;
			
		}
		
	}
	return false;
	
}



int main() {
	char b[3][3] = {
		{'.','x','.'},
		{'.','x','.'},
		{'.','.','.'}
	};
	char sol[3][3];
	int moves = 0;
	findPath(b,sol,0,0,0,2,moves);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Moves taken is "<<moves<<endl;
	return 0;
}