/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    map<RandomListNode*, RandomListNode*> m;
    RandomListNode *newHead = new RandomListNode(A->label);
    m[A] = newHead;
    
    RandomListNode *p = A;
    RandomListNode *q = newHead;
    RandomListNode *temp;
    p = p->next;
    temp = q;
    
    while(p){
        q = new RandomListNode(p->label);
        m[p] = q;
        
        p = p->next;
        temp->next = q;
        temp = q;
    }
    
    p = A;
    
    while(p){
        if(p->random)
            m[p]->random = m[p->random];
        else
            m[p]->random = NULL;
        p = p->next;
    }
    return newHead;
}
