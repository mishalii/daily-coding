leetcode
class Solution {
public:
    int minOperations(int n) {
        if(n==pow(2,(int)log2(n)))
        {
            return 1;
        }

        int low=pow(2,(int)log2(n));
        int high=pow(2,(int)log2(n)+1);


        int d1=n-low;
        int d2=high-n;

        return 1+min(minOperations(d1),minOperations(d2));
    }
};
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18

//gfg 

where only double and add sub was allowed
int minOperation(int n)
    {
        //code here
       int count=0;
       
       while(n!=0)
       {
           if(n%2==0)
           {
               n/=2;
           }
               
               else n--;
               
               count++;
           
       }
        
        return count;
    }
};
time complexity-o(logn)



