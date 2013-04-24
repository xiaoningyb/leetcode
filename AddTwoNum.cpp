#include <iostream>

using namespace std;


/*
  Add Two Numbers

  You are given two linked lists representing two non-negative numbers.
  The digits are stored in reverse order and each of their nodes contain a single digit.
  Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    bool carry = false;
    ListNode* ret = l1;
    while(l1 && l2)
    {
        int sum = l1->val + l2->val + (carry ? 1 : 0);
        if(sum > 9)
        {
            sum -= 10;
            carry = true;
        }
        else
        {
            carry = false;
        }
        
        l1->val = sum;
        
        if(l1->next)
        {            
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l2->next)
        {
            l1->next = l2->next;
            l1 = l2->next;
            break;
        }
        else if(carry)
        {
            l1->next = new ListNode(1);
            l1 = l1->next;
            carry = false;
            break;
        }
        else
            break;        
            
    }
    
    while(carry && l1)
    {
        l1->val++;
        if(l1->val > 9)
        {
            carry = true;
            l1->val -= 10;
            if(l1->next)
            {                
               l1 = l1->next;
            }            
            else if(carry)
            {
                l1->next = new ListNode(1);
                l1 = l1->next;
                carry = false;
                break;                
            }
            else
                break;
        }
        else
        {
            carry = false;
        }
    }
        
    return ret;
}

void print_list(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;    
}


int main()
{
    ListNode* n1 = new ListNode(1);

    ListNode* m2 = new ListNode(8);
    ListNode* m1 = new ListNode(9, m2);

    print_list(m1);

    print_list(n1);

    ListNode* ret = addTwoNumbers(m1, n1);

    print_list(ret);    
    
}
