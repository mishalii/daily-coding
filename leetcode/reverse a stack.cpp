void insert(stack<int>&s,int num)
{

    if(s.empty())
    {
        s.push(num);
        return;
    }
   int element=s.top();
   s.pop();
   insert(s,num);
   s.push(element);
}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty())return;//base case

    int num=s.top();
    s.pop();
    reverseStack(s);

    insert(s,num);
}
