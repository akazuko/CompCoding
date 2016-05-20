/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int h(TreeNode* root, int *k){
    if(root==NULL)  return -1;
    int p = h(root->left, k);
    if(p!=-1)       return p;
    *k = *k - 1;
    if(*k==0){
        return root->val;
    }        
    return h(root->right, k);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    return h(root, &k);
}
