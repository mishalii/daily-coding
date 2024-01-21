class Solution {
public:

    int  solve(vector<int>&nums,int index,vector<int>&dp)
    {
        int ans=0;
        int n=nums.size();

        if(index<0)return 0;

        if(index==0)return nums[index];

        if(dp[index]!=-1)return dp[index];

        int pick=nums[index]+solve(nums,index-2,dp);

        int notpick=0+solve(nums,index-1,dp);

        ans=max(pick,notpick);

        return dp[index]=ans;
    }
    int rob(vector<int>& nums) {
         int n=nums.size();

         vector<int>dp(n,-1);
         return solve(nums,n-1,dp);
        
    }
}; //by memoisation



class Solution {
public:

    int  solve(vector<int>&nums,int index)
    {
        int n=nums.size();
        vector<int>dp(n,0);
        int ans=0;
        

     dp[0]=nums[index];

        for(int i=1;i<n;i++)
        {


        int pick=nums[i];
        if(i>1){
        pick+=dp[i-2];
        }
        int notpick=0+dp[i-1];

       dp[i]=max(pick,notpick);




    }
    return dp[n-1];
    }
    int rob(vector<int>& nums) {
         int n=nums.size();

     

         return solve(nums,0);
         
        
    }
}; //by tabulisation

class Solution {
public:

    int  solve(vector<int>&nums,int index,vector<int>&dp)
    {
        int ans=0;
        int n=nums.size();

        if(index<0)return 0;

        if(index==0)return nums[index];

        if(dp[index]!=-1)return dp[index];

        int pick=nums[index]+solve(nums,index-2,dp);

        int notpick=0+solve(nums,index-1,dp);

        ans=max(pick,notpick);

        return dp[index]=ans;
    }
    int rob(vector<int>& nums) {
         int n=nums.size();

         vector<int>dp(n,-1);
         return solve(nums,n-1,dp);
        
    }
}; 

