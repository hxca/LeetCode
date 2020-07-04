/*
 *
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:
 *          Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *          Output: 7 -> 0 -> 8
 *          Explanation: 342 + 465 = 807.
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;

    int carry = 0;
    int x, y, sum;

    struct ListNode* lastp;
    struct ListNode* result = NULL;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        x = (p1 != NULL) ? p1->val : 0;
        y = (p2 != NULL) ? p2->val : 0;

        sum = carry == 1 ? x + y + 1 : x + y;
        carry = sum / 10;

        struct ListNode* cell;
        cell = (struct ListNode*)malloc(sizeof(struct ListNode));
        cell->val = sum % 10;
        cell->next = NULL;
        if (result == NULL) {
            result = cell;
            lastp = cell;
        } else {
            lastp->next = cell;
            lastp = cell;
        }

        if (p1 != NULL)
            p1 = p1->next;
        if (p2 != NULL)
            p2 = p2->next;
    }

    return result;
}
