// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Solution
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

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        if (n == len)
        {
            head = head->next;
            return head;
        }
        int m = len - n + 1;
        int idx = m - 1;
        temp = head;
        for (int i = 1; i <= idx - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};