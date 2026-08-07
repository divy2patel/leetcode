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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* sum=NULL;
        int c=0;

        while(temp1!=NULL&&temp2!=NULL)
        {
            int ans=temp1->val+temp2->val+c;
            if(sum==NULL)
            {
                if(ans>9)
                {
                    sum=new ListNode(ans-10);
                    c=1;
                }
                else
                {
                    sum=new ListNode(ans);
                    c=0;
                }
            }
            else
            {
                ListNode *temp3=sum;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                if(ans>9)
                {
                    ListNode *nn=new ListNode(ans-10);
                    c=1;
                    temp3->next=nn;
                }
                else
                {
                    ListNode *nn=new ListNode(ans);
                    c=0;
                    temp3->next=nn;
                }
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            int ans=temp1->val+c;
            int digit = (ans>9) ? ans-10 : ans; 
            c = (ans>9) ? 1 : 0;

            ListNode *temp3=sum;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
            ListNode *nn=new ListNode(digit);   
            temp3->next=nn;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            int ans=temp2->val+c;               
            int digit = (ans>9) ? ans-10 : ans;
            c = (ans>9) ? 1 : 0;
            ListNode *temp3=sum;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
            ListNode *nn=new ListNode(digit);   
            temp3->next=nn;
            temp2=temp2->next;
        }

        if(c!=0)
        {
            ListNode *temp3=sum;
            while(temp3->next!=NULL)
            {
                temp3=temp3->next;
            }
            ListNode *nn=new ListNode(c);
            temp3->next=nn;
        }

        return sum;
    }
};