/*
 Remove Nth Node From End of List

 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
   Given n will always be valid.
   Try to do this in one pass.
*/

ListNode *removeNthFromEnd(ListNode *head, int last) 
{
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    ListNode* pre = head;
    ListNode* cur = head;

    for(int i = 0; i < last; ++i)
    {
        if(!pre)
            return NULL;
        pre = pre->next;
    }
    
    if(pre == NULL)
    {
        head = head->next;
    }
    else
    {
        while(pre->next)
        {
            pre = pre->next;
            cur = cur->next;
        }
    
        cur->next = cur->next->next;
    }
    return head;

    }
};
