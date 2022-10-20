// reverse a linked list
// recurrsive approach


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
      the first element at the end */
    ListNode *rest = reverse(head->next);
    head->next->next = head;

    /* tricky step -- see the diagram */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}