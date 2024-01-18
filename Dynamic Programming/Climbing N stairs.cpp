

class Solution {
    const int MOD=1e9+7;
    
// private: int solve(int n,int i)
// {
//     vector<int>dp(n+1,0);
    
//  dp[0]=1;
//  dp[1]=1;

    
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n]; //return whats asked
// }

int solve(int n,int i)
{
    int prev1=1;
    int prev2=1;
    for(int i=2;i<=n;i++)
    {
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
public:
    int climbStairs(int n) {
        
        int ans=solve(n,0);
        return ans;
    }
};
