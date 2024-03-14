class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int presum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            presum=presum+nums[i];
            int remove=presum-goal;

             count=count+mpp[remove];

             mpp[presum]++;
        }

        return count;
    }
}; // first approach by hashing  time complexity-o(N)


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int window_sum=0;
        int count_zeroes=0;

        while(j<n)
        {
            window_sum=window_sum+nums[j];

            while(i<j && (nums[i]==0 ||window_sum>goal))
            {
                if(nums[i]==0 ){
                    count_zeroes++;
                }
                else 
                {
                    count_zeroes=0;
                }
                window_sum-=nums[i];
                i++;
            }

            if(window_sum==goal)
            {
                count+=1 +count_zeroes;
            }

            j++;
        }
        return count;
    }
}; // sliding window
