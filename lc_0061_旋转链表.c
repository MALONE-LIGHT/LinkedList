/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

*/

/*
思路：
旋转k个位置，与旋转k+n*Length个位置的结果一样
计算出链表的长度后，可以简化为旋转k%Length个位置
k=0，不需要旋转
k>0,第一个节点向右移动了k个位置
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(NULL == head || NULL == head->next)//链表长度小于2，旋转不会改变
    {
        return head;
    }

    //计算长度的同时得到末尾节点tail
    int length = 1;
    struct ListNode* tail = head;
    while(NULL != tail->next)//此句不能用NULL!=tail,因为tail会到达链尾节点指向的NULL
    {

        tail = tail->next;
        length++;
    }

    //计算需要旋转的次数
    k %= length;
    if(0 == k)//旋转0次时，链表不变
    {
        return head;
    }

    struct ListNode* pre = head;
    struct ListNode* newHead = pre;

    //第length-k+1个节点向右移动length-k次，变成链尾
    for(int i = 0; i < length - k; i++)
    {
        pre = newHead;
        newHead = newHead->next;
    }

    pre->next = NULL;
    tail->next = head;

    return newHead;
} 