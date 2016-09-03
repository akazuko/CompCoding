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
 
bool hasPathSum(Node *node, int sum)
{  
    
   if(node->left==NULL && node->right==NULL) return sum==(node->data);
   if(node->left!=NULL && hasPathSum(node->left, sum - node->data)) return true;
   if(node->right!=NULL && hasPathSum(node->right, sum - node->data)) return true;
   return false;
}
