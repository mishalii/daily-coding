class Solution {
public: vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>>& board,string& word,int index,int i,int j)
    {
          int m=board.size();
        int n=board[0].size();

        if(index==word.length())//we were able to find the complete word
        {
            return true;
        }

        if(i<0|| j<0 || i>=m||j>=n|| board[i][j]=='$')return false; // edge cases


        if(board[i][j]!=word[index])return false;

        char temp=board[i][j];//stored for backtracking
        board[i][j]='$';//mark it visited


        for(auto &dir :directions)
        {
                  int new_i=i+dir[0];//from the current index we will go in other directions so that's why we are travelling and adding
                  int new_j=j+dir[1];

                  if(find(board,word,index+1,new_i,new_j))return true; //now run the loop and find for i in all 4 directions
        }

        //backtrack if the result is false

        board[i][j]=temp;


        return false;//if we cant fidn word from all the directions then return false




    }
    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
           for(  int j=0;j<n;j++)
            {

               if(board[i][j]==word[0]&& find(board,word,0,i,j))
               {
                   return true;
               }

            }
        }

        return false;
        
    }
};
