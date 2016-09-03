/* A binary tree node
struct node
{
    int data;
    struct Node* left, * right;
}; */

/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL || r2==NULL) return false;
    if(!isIdentical(r1->left, r2->left)) return false;
    if(!isIdentical(r1->right, r2->right)) return false;
    return true;
}
