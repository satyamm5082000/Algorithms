#include<bits/stdc++.h>
using namespace std;

bool ifpossible(int **board,int n,int row,int col)
{
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col])
        {
            return false;
        }
    }

    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
            if(board[i][j])
            {
                return false;
            }
        }
    }
    
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col+1;j<n;j++)
        {
            if(board[i][j])
            {
                return false;
            }
        }
    }

   return true;

}

void NQueenstart(int n,int **board,int row)
{
    
    if(row==n)
    {

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
    }
    
    for(int i=0;i<n;i++)
    {
      if(ifpossible(board,n,row,i))
      {
    
          board[row][i]=1;
          NQueenstart(n,board,row+1);
          board[row][i]=0;
      }
    }

    return;

}

void NQueenprob(int n,int **board)
{
    NQueenstart(n,board,0);
}

int main()
{
    int n;
    cin>>n;

    
    
    int **board= new int *[n+1];
  
    for(int i=0;i<=n;i++)
    {
        board[i]=new int [n+1];

        for(int j=0;j<=n;j++)
        {
              board[i][j]=0;
        }
    }
    


    NQueenprob(n,board);
}