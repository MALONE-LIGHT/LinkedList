/* 
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/*
思路：
遍历两个链表，逐位计算每个节点数据域的和，和大于10则进位，新链表节点的数据域的值等于输入的两个链表的节点数据域以进位的和。

step1：遍历L1和L2两个链表，计算节点数据域的和n1+n2，计算进位值carry。
step2：创建新链表节点，数据域的值为n1+n2+carry
stemp3:当遍历L1和L2结束后，判断是否有进位，若有进位则需在新链表创建节点保存进位值。
*/

/* START
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int carry = 0;

    while(l1 || l2)
    {
        int n1 = l1? l1->val: 0;
        int n2 = l2? l2->val: 0;
        int sum = n1 + n2 + carry;
        
        if(NULL == head)//创建头节点，并赋值
        {
            head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->val = sum % 10;//计算新链表的数据域的值
            tail->next = NULL; 
        }
        else
        {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));//创建新节点
            tail->next->val = sum % 10;//
            tail = tail->next;//与最后一个节点关联，并将新节点作为尾节点
            tail->next = NULL;
        }
        

        carry = sum / 10;//计算是否有进位值

        if(l1)
        {
            l1 = l1->next;//遍历L1，L1中节点指向NULL,说明已到达最后一个节点
        }
        if(l2)
        {
            l2 = l2->next;
        }
    }

    if(carry > 0)//遍历两个链表完成后，若扔存在进位值，说明新链表需要一个新的节点去保存进位值。
    {
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }

    return head;
}
