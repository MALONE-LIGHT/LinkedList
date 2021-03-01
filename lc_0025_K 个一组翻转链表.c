/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

*/

/*
思路：
把k个一组分组，使用head依次指向每组的头节点。指针每次向前移动k步，直至链表结尾。
每个分组先判断长度是否大于等于k，若是则翻转这部分链表，若不是则不需要翻转。
翻转一个分组內的子链表，除了翻转其本身之外，还需要将子链表的头部与上一个子链表连接，子链表的尾部与下一个子链表连接。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct List
{
    struct ListNode* head;
    struct ListNode* tail;
}LIST;

LIST* myReverse(LIST *temp)
{
    LIST* result = malloc(sizeof(LIST));
    struct ListNode* prev = temp->tail->next;
    struct ListNode* p = temp->head;

    while(prev != temp->tail)
    {
        struct ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    
    result->head = temp->tail;
    result->tail = temp->head;
    return result;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode * hair = malloc(sizeof(struct ListNode));
    hair->next = head;
    struct ListNode* pre = hair;


    while(head)
    {
        struct ListNode *tail = pre;
        for(int i = 0 ; i < k; i++)
        {
            tail = tail->next;
            if(NULL == tail)
            {
                return hair->next;
            }
        }
        struct ListNode* nex = tail->next;
        LIST *temp = malloc(sizeof(LIST));
        temp->head = head;
        temp->tail = tail;

        LIST* result = malloc(sizeof(LIST));
        result = myReverse(temp);//反转子链表中的节点

        pre->next = result->head;//子链表的头部与上一个子链表连接
        result->tail->next = nex;//子链表的尾部与下一个子链表连接
        pre = result->tail;
        head = result->tail->next;
    }

    return hair->next;
}