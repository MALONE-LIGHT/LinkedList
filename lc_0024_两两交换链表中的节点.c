/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例 1：

输入：head = [1,2,3,4]
输出：[2,1,4,3]

*/

/*
思路：
递归
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    //递归结束的条件
    if(NULL == head || NULL == head->next)
    {
        return head;
    }

    //以1->2->3->4为例
    //newhead第一次保存节点2，第2次保存节点4
    struct ListNode * newhead = head->next;
    //第一次将1指向后面节点4->3，第二次将3指向后面节点NULL
    head->next = swapPairs(newhead->next);
    //第一次将2指向1，第二次将4指向3
    newhead->next =  head;

    return newhead;
}