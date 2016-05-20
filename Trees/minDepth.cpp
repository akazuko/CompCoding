/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int h1=100000;
        int h2=100000;
        if(root->left!=NULL)
            h1=minDepth(root->left);
        if(root->right!=NULL)
            h2=minDepth(root->right);
    
        return 1+(h1<h2?h1:h2);
    }
};