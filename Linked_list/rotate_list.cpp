/**61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
**/
// Solution
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        int n = 0;
        ListNode *temp = head;
        ListNode *tail = head;
        while (temp != nullptr)
        {
            if (temp->next == nullptr)
                tail = temp;
            temp = temp->next;
            n++;
        }
        k = k % n;
        if (k == 0)
            return head;
        temp = head;
        for (int i = 1; i < n - k; i++)
        {
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};