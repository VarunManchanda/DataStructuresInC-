#include <iostream>
#include <set>
using namespace std;

int x[] = {0,1,1,1,0,-1,-1,-1};
int y[] = {1,0,1,-1,-1,-1,0,1};

bool isValid(bool visited[3][3], int rowNew, int colNew)
{
    if(rowNew>=0 && colNew>=0 && rowNew<3 && colNew<3 && (!visited[rowNew][colNew]))
    {
        return true;
    }
    return false;
}


void boggle(char board[3][3], bool visited[3][3], int row, int col, string word, multiset<string> dictionary)
{
	if(dictionary.find(word)!=dictionary.end())
	{
		cout << word << endl;
	}
    for(int i=0; i<8; i++)
    {
        int rowNew = row + x[i];
        int colNew = col + y[i];
        if(isValid(visited,rowNew,colNew))
        {
            visited[rowNew][colNew] = true;
            boggle(board,visited,rowNew,colNew,word+board[rowNew][colNew],dictionary);
            visited[rowNew][colNew] = false;
        }
    }
	
}

int main() {
	char board[3][3] =    {{'F','O','B'},
                           {'O','A','E'},
                           {'K','S','C'}};
    bool visited[3][3] = {{false,false,false},
                          {false,false,false},
                          {false,false,false}};
    string word = "";
    multiset<string> dictionary = {"FACE","BOOKS","ACES","BES"};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            visited[i][j] = true;
            boggle(board,visited,i,j,word+board[i][j],dictionary);
            visited[i][j] = false;
        }
    }
	return 0;
}