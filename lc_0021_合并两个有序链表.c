/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/

/*
思路：
设定一个哑结点preHead，这样有助于返回合并后的链表。逐个比较两个链表的节点数据域的值大小，把较小值的节点添加到到结果中，将此链表的节点移动到下一位，将结果链表移动到下一位，继续比较直至两个链表其中一个达到链尾。将结果链表指向未合并完的链表。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    preHead->val = -1;
    preHead->next = NULL;

    struct ListNode *prev = preHead;
    while(NULL != l1 && NULL != l2)
    {
        if(l1->val < l2->val)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        
        prev = prev->next;
    }
    prev->next = l1 == NULL ? l2 : l1;
    return preHead->next;
}