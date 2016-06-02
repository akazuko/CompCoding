/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode* nextRight(TreeLinkNode* p){
    TreeLinkNode* temp = p->next;
    while(temp){
        if(temp->left) return temp->left;
        if(temp->right) return temp->right;
        temp = temp->next;
    }
    return NULL;
}

void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* q;
    TreeLinkNode* p;
    
    if(!A) return;
    
    A->next = NULL;
    
    p = A;
    while(p){
        q = p;
        
        while(q){
            if(q->left){
                if(q->right)
                    q->left->next = q->right;
                else
                    q->left->next = nextRight(q);
            }
        
            if(q->right){
                q->right->next = nextRight(q);
            }
            
            q = q->next;
        }
        
        if(p->left) p = p->left;
        else if(p->right) p = p->right;
        else p = nextRight(p);
    }
    
}
