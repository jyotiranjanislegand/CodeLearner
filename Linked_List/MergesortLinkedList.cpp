class Solution {
    ListNode *mergeSort(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *curr = &dummy;
        
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            
            curr = curr->next;
        }
        
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        
        return mergeSort(l1, l2);
    }
};
