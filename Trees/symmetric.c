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
int same(treenode* one, treenode* two){
    if(one==NULL && two!=NULL)
        return 0;
    if(one!=NULL && two==NULL)
        return 0;
    if(one==NULL && two==NULL)
        return 1;
    if(same(one->left,two->right)==0)
        return 0;
    if(one->val!=two->val)
        return 0;
    if(same(one->right,two->left)==0)
        return 0;
    return 1;
}

int isSymmetric(treenode* A) {

    return same(A,A);
}
