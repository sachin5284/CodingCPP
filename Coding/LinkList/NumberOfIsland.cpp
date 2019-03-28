#include<iostream>
#include<string.h>

const int ROW=5;
#define COL 5
using namespace std;

bool isSafe(int M[][COL],int row,int col,bool visited[][COL])
{
    return (row>=0) && (row<ROW) && (col>=0) && col<COL && M[row][col] && !visited[row][col];
}

void DFS(int M[][COL],int row,int col,bool visited[][COL])
{
    pair<int,int> nbr[]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,1}};

    visited[row][col]=true;

    for(int i=0;i<8;i++)
    {
        if(isSafe(M,row+nbr[i].first,col+nbr[i].second,visited))
            DFS(M,row+nbr[i].first,col+nbr[i].second,visited);
    }
}

int countIslands(int M[][COL])
{
    bool visited[ROW][COL]; 
    memset(visited, 0, sizeof(visited)); 
    int count=0;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int M[][COL]= {  {1, 1, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 1}, 
        {0, 0, 0, 0, 0}, 
        {1, 0, 1, 0, 1} 
    }; 
  
    printf("Number of islands is: %d\n", countIslands(M));
}