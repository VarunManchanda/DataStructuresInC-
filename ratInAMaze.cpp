#include <iostream>
#include <vector>
using namespace std;
int x[] = {0,1};
int y[] = {1,0};

int finalR = 0;
int finalC = 0;

bool isValid(vector<vector<char>> maze, vector<vector<bool>> visited, int i, int j)
{
    if(i<0 || j<0 || i>finalR-1 || j>finalC-1 || (visited[i][j]==true) || (maze[i][j]=='X'))
    {
        return false;
    }
    return true;
}

void print(vector<vector<bool>> &visited)
{
    for(int i=0; i<finalR; i++)
    {
        for(int j=0; j<finalC; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

bool ratInMaze(vector<vector<char>> maze, vector<vector<bool>> visited, int si, int sj, int fi, int fj)
{
    //base case
    if(si==fi && sj==fj)
    {
       // visited[fi][fj] = true;
        print(visited);
        return true;
    }
    //recursive case
    for(int i=0; i<2; i++)
    {
        int newI = si + x[i];
        int newJ = sj + y[i];
        if(isValid(maze,visited,newI,newJ))
        {
            visited[newI][newJ] = true;
            if(ratInMaze(maze,visited,newI,newJ,fi,fj))
            {
                return true;
            }
            visited[newI][newJ] = false;
        }
    }
    return false;
}

int main() {
    int row , col;
    cin >> row >> col;

    finalR = row;
    finalC = col;

    vector<vector<char>> maze(row, vector<char>(col));
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> maze[i][j];
        }
    }
    bool ans = ratInMaze(maze,visited,0,-1,row-1,col-1);
    if(ans)
    {
        cout << "Path is present!!" << endl;
    }
    else
    {
        cout << "Path is not present!!" << endl;
    }
    return 0;
}
