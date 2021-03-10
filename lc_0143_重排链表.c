/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.


/*
思路：
利用线性表存储该链表，然后利用线性表可以下标访问的特点，直接按顺序访问指定元素，重建该链表即可
*/

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head)
 {
    if (head == NULL) {
        return;
    }
    struct ListNode* vec[40001];
    struct ListNode* node = head;
    int n = 0;
    while (node != NULL) {
        vec[n++] = node;
        node = node->next;
    }
    int i = 0, j = n - 1;
    while (i < j) {
        vec[i]->next = vec[j];
        i++;
        if (i == j) {
            break;
        }
        vec[j]->next = vec[i];
        j--;
    }
    vec[i]->next = NULL;
}
