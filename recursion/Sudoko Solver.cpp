class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(int c='1';c<='9';c++)
                    {
                        if(isvalid(board,i,j,c))
                        {
                            board[i][j]=c;

                            if (solve(board)==true) return true; // that means that place is correctly filled

                            else board[i][j]='.'; //else backtrack and try other numbers on that position
                        }
                    }
                    return false;
                }
            }
        }

        return true;//for the last case when there are no empty cells left
    }

    bool isvalid(vector<vector<char>>& board,int row,int col,int num)
    {
        for(int i=0;i<9;i++)
        {
           if(board[row][i]==num)return false; // keeping row  constant and checking all through  that column

           if(board[i][col]==num) return false; // keeping column constant and checking all through the row

           if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num)return false;

           // as each row in a submatrix and column is of length 3 
           // now when you do a 3* row this remains constant and by i/3 you can shift to the next row but simultaneously i%3 helps you to traverse all the columns and then i/3 moves you to the next row
        }

        return true;
    }
};
