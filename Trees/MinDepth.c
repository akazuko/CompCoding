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
int minDepth(treenode* A) {
    if(A!=NULL && A->left==NULL && A->right==NULL)
        return 1;
    if(A==NULL)
        return 0;
    int h1=1000000;
    int h2=1000000;
    
    if(A->left!=NULL)
        h1=minDepth(A->left);
    if(A->right!=NULL)
        h2=minDepth(A->right);
    if(h1<h2)
        return 1+h1;
    return 1+h2;
}
