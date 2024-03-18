//when sorted on basis of endpoint
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        int count         = 1;
        int lastEndPoint  = points[0][1];
        
        for(int i = 1; i<n; i++) {
            int curr_startPoint = points[i][0];
            
            if(curr_startPoint > lastEndPoint) {
                count++;
                lastEndPoint = points[i][1];
            }
        }
        
        return count;
    }
};

//when sorted on basis of startpoint
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int>prev=points[0];

        int count=1;
        for(int i=1;i<n;i++)
        {
            int currstartpoint=points[i][0];
            int currendpoint=points[i][1];

            int prevstartpoint=prev[0];
            int prevendpoint=prev[1];

            if(currstartpoint>prevendpoint)
            {
                //no overlap
                count++;
                prev=points[i];
            }

            else
            {
                //overlap
                prev[0]=max(prevstartpoint,currstartpoint);
                prev[1]=min(prevendpoint,currendpoint);
            }
        }
        return count;
    }
};


//TIME COMPLEXITY

O(NLOGN)
//SPACE COMPLEXITY

O(1)
