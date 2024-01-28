class Solution {
public:


    int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	int low=0;

	int ans=n;
	int high=n-1;
	

	while(low<=high)
	{

		int mid=(low+high)/2;
		if(arr[mid]>=x)
		{
			ans=mid;
			high=mid-1;
		}

		else 
		{
			low=mid+1;
		}
	}

	return ans;
}

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	

	int low=0;

	int ans=n;
	int high=n-1;
	

	while(low<=high)
	{

		int mid=(low+high)/2;
		if(arr[mid]>x)
		{
			ans=mid;
			high=mid-1;
		}

		else 
		{
			low=mid+1;
		}
	}

	return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans(2,-1);
    int lb=lowerBound(nums,n,target);
    if(lb==n||nums[lb]!=target)
    {
       return ans;
    }

    ans[0]=lb;
    int ub=upperBound(nums,target,n);
    ans[1]=ub-1;

    return ans;
        
    }
};
