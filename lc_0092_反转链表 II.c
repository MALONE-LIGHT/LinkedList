/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

*/

/*
思路：
依次翻转从m到n节点的指针，反转后的头部与m之前的节点链接，尾部与n之后的节点链接。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if(NULL == head)
    {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    while(m > 1)
    {
        prev = cur;
        cur = cur->next;
        m--;
        n--;
    }

    struct ListNode* con = prev;
    struct ListNode* tail = cur;
    struct ListNode* third = NULL;

    while(n > 0)
    {
        third = cur->next;
        cur->next = prev;
        prev = cur;
        cur = third;
        n--;
    }

    if(NULL != con)
    {
        con->next = prev;
    }
    else
    {
        head = prev;
    }
    tail->next = cur;
    return head;
}