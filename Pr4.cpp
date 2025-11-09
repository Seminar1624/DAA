#include <iostream>
#include <vector>
using namespace std;


void printBoard(vector<vector<int>> &board,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==1)
                cout<<"Q ";
            else
                cout<<". ";    
        }
        cout<<endl;

    }
}

bool isSafe(vector<vector<int>> &board,int row,int col,int N)
{
    // check th column for same row
    for(int i=0;i<row;i++)
    {
        if(board[i][col]==1)
            return false;
    }
    // check the upper left diagonal
    for(int i=row,j=col;i>=0 &&j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    // check upper right diagonal
    for(int i=row,j=col;i>=0 && j<N;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    return true;
}
bool solveNQueens(vector<vector<int>> &board,int row,int N)
{
    if(row==N)
    {
        return true;
    }
    cout<<"After the iteration The matrix is : "<<endl;
        printBoard(board,N);

    for(int col=0;col<N;col++)
    {
        if(isSafe(board,row,col,N))
        {
            board[row][col]=1;

            if(solveNQueens(board,row+1,N))
                return true;

            board[row][col]=0;    
        }

    }
    return false;
}


int main()
{
    int N;
    cout<<"Enter the number of queens (N)"<<endl;
    cin>>N;
    int choice;
    vector<vector<int>> board(N,vector<int>(N,0));
 
        if(solveNQueens(board,0,N))
        {
            cout<<"Solution found: " <<endl;
            printBoard(board,N);
        }
        else{
            cout<<"solution doesn't exist"<<endl;
        }
    
    return 0;
}