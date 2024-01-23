class Solution {
public:
    bool hasduplicate(string &s1,string &s2)
    {
        int arr[26]={0};//array fro maintaing frequency of all characters
        for(char &ch :s1)
        {
            //checking for the string itself
            if(arr[ch-'a']>0)
            {
                return true;
            }


            arr[ch-'a']++;
        }

        for(char &ch:s2)
        {
            if(arr[ch-'a']>0)
            {
                return true;
            }
        }

        return false;
    }

    int solve(int index,vector<string>&arr,string temp,int n)
    {
        if(index>=n)
        {
            return temp.length();
        }


        int include=0;
        int exclude=0;

        if(hasduplicate(arr[index],temp))//must be checked first in the string itself
        {
            exclude=solve(index+1,arr,temp,n);
        }

        else 
        {
            exclude=solve(index+1,arr,temp,n);
            include=solve(index+1,arr,temp+arr[index],n);
        }


        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(0,arr,temp,n);

    }
};
