/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

 

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

*/


/*
思路：
设置两个链表，第一个链表存放小于x的值，第二个链表存放大于或等于x的值。
将第二个链表接在第一个链表的尾部。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* newhead1 = (struct LisatNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newhead2 = (struct LisatNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur1 = newhead1;
    struct ListNode* cur2 = newhead2;
    struct ListNode* p = head;

    while(p)
    {
        if(p->val < x)
        {
            cur1->next = p;
            cur1 = cur1->next;
        }
        else
        {
            cur2->next = p;
            cur2 = cur2->next;
        }

        p = p->next;
        
    }

    //这两句顺序不能颠倒
    cur2->next = NULL;
    cur1->next = newhead2->next;
    

    return newhead1->next;
}
