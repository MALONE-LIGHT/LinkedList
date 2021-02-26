/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

*/


/*
思路：
在合并两个有序链表的基础上，逐个合并有序链表。
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode * ans = NULL;

    for(int i = 0; i < listsSize; i++)
    {
        ans = mergeTwoLists(ans, lists[i]);
    }

    return ans;
}