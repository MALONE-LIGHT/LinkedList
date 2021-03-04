/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/

/*
思路：找出链表元素的中位数作为根节点的值。使用分治思想递归地对左右子树进行构造。
1.首先找到链表中位数作为根节点，将链表分为两个新链表
2.继续寻找两个新链表的中位数分别作为根节点的左右子节点，生成新的四个链表
3.通过递归继续寻找中位数
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct ListNode* getMedian(struct ListNode* left, struct ListNode* right) {
    struct ListNode* fast = left;
    struct ListNode* slow = left;
    while (fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct TreeNode* buildTree(struct ListNode* left, struct ListNode* right) {
    if (left == right) {
        return NULL;
    }
    struct ListNode* mid = getMedian(left, right);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = root->right = NULL;
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return buildTree(head, NULL);
}
