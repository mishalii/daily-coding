https://leetcode.com/problems/reorder-list/
APPROACH-1
1-find middle node
2-reverse from middlenode to end
3-write a while loop to make connections

Time complexity-O(N)
Space complexity for reversing by recursion stack space-0(n/2)==o(N)

  class Solution {
public:
    ListNode*reverse(ListNode*head)
    {
        if(head==NULL || head->next==NULL)return head;

        ListNode*last=reverse(head->next);
        head->next->next=head;// take an example of 5->2 so 5->next->next must be pointing to 5 after reversal
        head->next=NULL;//and 5 must be pointing ot null
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&& fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* rev=reverse(slow);//reversed list ka head rev mai store hojayega
        ListNode* curr=head;
        while(rev->next!=NULL)
        {
            ListNode*temp=curr->next;
            curr->next=rev;
            ListNode*prev=rev->next;
            rev->next=temp;
            curr=temp;
            rev=prev;
        }
    }
};


Approach-2

using stack
k=stack.size()/2;
while(k>0)
{
  Listnode*top=st.top();
  st.pop();
  listnode*temp=curr->next;
  curr->next=top;
  top->next=temp;
  curr=temp;
}
to finish self loop 
curr->next=NULL;



APPROACH-3 recursively finding the head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*curr;
    void solve(ListNode*head)
    {
        if(head==NULL)
        {
            return;
        }
        solve(head->next);

        ListNode*temp=curr->next;
        if(curr->next==NULL)// for odd linked list
        {
            return;
        }
        else if(curr==head)
        {
            curr->next=NULL;
            return;
        }
        curr->next=head;


        
        head->next=(temp==head)?NULL:temp;
        curr=temp;
    }
    void reorderList(ListNode* head) {
        curr=head;
        solve(head);
       

    }
}; //time complexity-O(N)
Space complexity-O(n)

  

  
