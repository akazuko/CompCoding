/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
int h(treenode* A){
    if(A==NULL) return 0;
    int h1 = h(A->left);
    int h2 = h(A->right);
    return 1 + (h1>h2?h1:h2);
}
int isBalanced(treenode* A) {
    if(A==NULL)
        return 1;
    int a=isBalanced(A->left);
    if(a==0)
        return 0;
    a=isBalanced(A->right);
    if(a==0)
        return 0;
    int h1 = h(A->left);
    int h2 = h(A->right);
    if(h1>h2){
        if(h1-h2>1){
           return 0;
        }
        else{
            return 1;
        }
    }
    
    if(h2>h1){
        if(h2-h1>1){
           return 0;
        }
        else{
            return 1;
        }
    }
    
    if(h1==h2) return 1;
    
}
