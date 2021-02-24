/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

/*
思路一：
先反转链表，然后删除第n个节点，最后再反转链表（3次遍历）

思路二：
使用两个指针，第一个指针先遍历至第n个节点，随后第二个指针开始遍历，当第一个指针到达链表末尾时，第二个指针刚好位于倒数第n个节点（1次遍历）
*/

//思路二解法
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *del_prior = malloc(sizeof(struct ListNode));
    del_prior->val = 0;
    del_prior->next = head;

    struct ListNode *first = head;
    struct ListNode *second = del_prior;

    for(int i = 0; i < n; i++)
    {
        first = first->next;
    }

    while(first)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;

    struct ListNode* ans = del_prior->next;//若删除的为链表第1个节点，则需要此操作
    free(del_prior);

    return ans;
}