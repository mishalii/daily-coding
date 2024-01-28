class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        //find the cummulative sum row wise
        for(int row=0;row<rows;row++)
        {
            for(int col=1;col<cols;col++)
            {
                matrix[row][col]+=matrix[row][col-1];
            }
        }

        int result=0;

        //traverse in the matrix finding the subarrays with prefix sum logic

        //in downward direction
        for(int startcol=0;startcol<cols;startcol++)
        {
            for(int j=startcol;j<cols;j++)//to traverse matrix wise
            {
                unordered_map<int,int>mpp;
                mpp[0]=1;
                int cumsum=0;

                for(int row=0;row<rows;row++)
                {
                    cumsum+=matrix[row][j]-(startcol>0?matrix[row][startcol-1]:0); // to avoid finding the sum twice as cumsum has already been calculated

                    if(mpp.find(cumsum-target)!=mpp.end())
                    {
                        result+=mpp[cumsum-target];
                    }
                    mpp[cumsum]++;
                }


            }
        }
        return result;

    }
};
