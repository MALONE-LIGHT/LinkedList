/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

*/

/**c 还需调试
* Definition for a Node.
* struct Node {
*     int val;
*     struct Node *next;
*     struct Node *random;
* };
*/


struct Node* copyRandomList(struct Node *head)
{
    if(head==NULL) 
    {
        return head;
    }
    struct Node *p = head;
    //第一步，在每个原节点后面创建一个新节点
    //1->1'->2->2'->3->3'
    while(p!=NULL)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = p->next;
        p->next = newNode;
        p = newNode->next;
    }
    p = head;
    //第二步，设置新节点的随机节点
    while(p!=NULL)
    {
        if(p->random!=NULL) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }
    struct Node *dummy = (struct Node*)malloc(sizeof(struct Node));
    p = head;
    struct Node *cur = dummy;
    //第三步，将两个链表分离
    while(p!=NULL)
    {
        cur->next = p->next;
        cur = cur->next;
        p->next = cur->next;
        p = p->next;
    }
    return dummy->next;
}

/*c++
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        copyNodes(head); // 拷贝 value 和 next
        copyRandom(head); // 拷贝 random
        return getCopy(head); // 提取出新的链表
    }
    void copyNodes(Node* head)
    {
        // 将 a -> b -> c 的链表变成 a -> a' -> b -> b' -> c -> c'
        if(!head) return;
        Node* pos = head;
        while(pos)
        {
            Node* copy = new Node(pos -> val);
            Node* nextPtr = pos -> next;
            pos -> next = copy;
            copy -> next = nextPtr;
            pos = copy -> next;
        }
    }
    void copyRandom(Node* head)
    {
        if(!head) return;
        Node* pos = head;
        while(pos)
        {
            // 例：a -> a' -> b -> b' -> c -> c'
            // 假如 a -> random存在，则 a' -> random 一定等于 a -> random -> next
            // 假如 a -> random不存在，则 a' -> random == nullptr
            Node* copy = pos -> next;
            Node* oldRandom = pos -> random;
            if(oldRandom) copy -> random = oldRandom -> next;
            else copy -> random = nullptr;
            pos = copy -> next;
        }
    }
    Node* getCopy(Node* head)
    {
        if(!head) return head;
        Node* pos = head;
        Node* copy = pos -> next;
        Node* newHead = copy;
        while(pos)
        {
            // 将原链表与复制出的链表提取成两条单独的链表，并返回复制出的链表
            pos -> next = copy -> next;
            pos = pos -> next;
            if(pos) copy -> next = pos -> next;
            copy = copy -> next;
        }
        return newHead;
    }
};
