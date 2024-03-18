// top down recursion + memoisation

class Solution {
public:

    int solve(int i,vector<vector<int>>&pairs,int prev,vector<vector<int>>&dp)

    {
        int n=pairs.size();
        if(i==n)return 0;
        int take=0;

        if(prev==-1|| pairs[prev][1]<pairs[i][0])
        {
            take=1+solve(i+1,pairs,i,dp);
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int nottake=solve(i+1,pairs,prev,dp);

        int ans=max(take,nottake);
        dp[i][prev+1]=ans;

        return ans;

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,pairs,-1,dp);
    }
};



// bottom up tabularization

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);

        int maxlis=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                dp[i]=max(dp[i],dp[j]+1);
                maxlis=max(maxlis,dp[i]);
            }
        }
        return maxlis;
    }
};  



//time complexity-o(n^2)
