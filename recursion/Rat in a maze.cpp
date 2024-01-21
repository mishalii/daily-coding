NOT OPTIMISED
class Solution{
    public:
    
    void solve(int i,int j,vector<vector<int>>&a,int n,vector<string>&ans,string move,vector<vector<int>>&vis)
    {
        //base case
        if(i==n-1 && j==n-1) // when reached the destination then push back the ans to vector
        {
            ans.push_back(move);
            return;
        }
        
        //donward
        if(i+1<n && a[i+1][j]==1 && !vis[i+1][j])
        {
            //mark it visited
            vis[i][j]=1;
            solve(i+1,j,a,n,ans,move+'D',vis);
            vis[i][j]=0;//while coming back;
            
            
        }
        
        if(j-1>=0 && a[i][j-1]==1 && !vis[i][j-1])
        {
            //mark it visited
            vis[i][j]=1;//marking the previous one visited
            solve(i,j-1,a,n,ans,move+'L',vis);
            vis[i][j]=0;//while coming back;
            
            
        }
        
        
        //right
        if(j+1<n && a[i][j+1]==1 && !vis[i][j+1])
        {
            //mark it visited
            vis[i][j]=1;
            solve(i,j+1,a,n,ans,move+'R',vis);
            vis[i][j]=0;//while coming back;
            
            
        }
        
        //upward
        if(i-1>=0 && a[i-1][j]==1 && !vis[i-1][j])
        {
            //mark it visited
            vis[i][j]=1;
            solve(i-1,j,a,n,ans,move+'U',vis);
            vis[i][j]=0;//while coming back;
            
            
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1) solve(0,0,m,n,ans,"",vis);
        return ans;
    }
};





//optimised


// User function template for C++

class Solution{
    public:
    
    void solve(int i,int j,vector<vector<int>>&a,int n,vector<string>&ans,string move,vector<vector<int>>&vis,int di[],int dj[])
    {
        //base case
        if(i==n-1 && j==n-1)
        {
            ans.push_back(move);
            return;
        }
        
        
        //simply maintain two arrows for directions and check which one to move
        string dir="DLRU";
        for(int ind=0;ind<4;ind++)// to check 4 times for each cell
        {
           int nexti=i+di[ind]; 
           int nextj=j+dj[ind];
           
           if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1)
           {
               vis[i][j]=1;
               solve(nexti,nextj,a,n,ans,move+dir[ind],vis,di,dj);
               vis[i][j]=0;
               
           }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        
        if(m[0][0]==1) solve(0,0,m,n,ans,"",vis,di,dj);
        return ans;
    }
};

    
