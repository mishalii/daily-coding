class Solution {
public:

   bool issafe(int row,int col,vector<string>&board,int n)
   {
       int duprow=row;
       int dupcol=col;
      //to check upper diagonal
       while(row>=0 && col>=0)
       {
           if(board[row][col]=='Q')return false;
           row--;
           col--;//both will decrease
       }
       col=dupcol;
       row=duprow;

       while(col>=0) 
       {
           if(board[row][col]=='Q')return false;
           col--;
       }//to check left

          col=dupcol;
       row=duprow;
       while(col>=0 && row<n)
       {
           if(board[row][col]=='Q')return false;
           col--;
           row++;
       }

       return true;
   }

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }


        //exploration will be done in board in each column we will explore for all the rows
        for(int row=0;row<n;row++)
        {
          if(issafe(row,col,board,n))
          {
              board[row][col]='Q';
              solve(col+1,board,ans,n);
              board[row][col]='.';//backtracking step
          }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');//generating empty strings of n size to place in n  size vector

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        solve(0,board,ans,n);

        return ans;

        
    }
};


class Solution {
public:

  

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&leftrow,vector<int>&lowerdiagonal,vector<int>&upperdiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }


        //exploration will be done in board in each column we will explore for all the rows
        for(int row=0;row<n;row++)
        {
          if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1+ col-row]==0)
          {
              board[row][col]='Q';
              leftrow[row]=1;
              lowerdiagonal[row+col]=1;
              upperdiagonal[n-1+col-row]=1;
              solve(col+1,board,ans,n,leftrow,lowerdiagonal,upperdiagonal);
              board[row][col]='.';
              //backtracking step
              leftrow[row]=0;
              lowerdiagonal[row+col]=0;
              upperdiagonal[n-1+col-row]=0;

          }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');//generating empty strings of n size to place in n  size vector

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        solve(0,board,ans,n,leftrow,upperdiagonal,lowerdiagonal);

        return ans;

        
    }
};








//optimal way to find is it safe to place a queen or not


