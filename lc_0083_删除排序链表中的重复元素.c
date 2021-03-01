/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/

/*
思路：
从头节点开始，依次和后继节点的值进行比较，如果相同将当前节点的next指向后继节点的next。
记得释放节点。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* p = head;
    if(NULL == p)
    {
        return head;
    }

    while(p->next)
    {
        struct ListNode* q = p->next;
        if(p->val == q->val)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }

    }

    return head;
}