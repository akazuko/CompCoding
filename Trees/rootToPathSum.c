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
 * @input B : Integer
 * 
 * @Output Integer
 */
 
int trav(treenode* root, int sum){
        //printf("%d\n", root->val);
    
    if(root==NULL)
        return sum==0;
    
    int subSum=sum-root->val;
    if(subSum==0 && root->left==NULL && root->right==NULL)
        return 1;
    
    if(root->left!=NULL && trav(root->left, subSum)==1)
        return 1;
    if(root->right!=NULL && trav(root->right, subSum)==1)
        return 1;
    return 0;
}
int hasPathSum(treenode* A, int B) {
    return trav(A, B);
}
