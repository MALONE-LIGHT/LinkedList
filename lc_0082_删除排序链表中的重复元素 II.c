/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = &dummy;

    while(NULL != cur->next && NULL != cur->next->next)
    {
        if(cur->next->val == cur->next->next->val)
        {
            //通过temp找到重复数字中的最后一个节点位置
            struct ListNode* temp = cur->next;
            while(NULL != temp && NULL != temp->next && temp->val == temp->next->val)
            {
                temp = temp->next;
            }
            
            //跳过重复数字的节点，指向下一个新的数字节点
            cur->next = temp->next;
            free(temp);
        }
        else
        {
            cur = cur->next;
        }
    }

    return dummy.next;
}

