class Solution {
public:

    bool isvowel(char ch)
    {
        if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'|| ch=='u'|| ch=='A'|| ch=='E'||ch=='O'||ch=='I'||ch=='U')return true;

        else return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
       int countleft=0;
       int countright=0;
       int i=0;
       int j=n/2;
       while(i<n/2 && j<n) 
       {
           if(isvowel(s[i]))countleft++;

           if(isvowel(s[j]))countright++;
           i++;
           j++;
       }

      return countleft==countright;

    }
};
