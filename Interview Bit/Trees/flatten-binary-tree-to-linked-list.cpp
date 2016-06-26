/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* getTree(TreeNode* A){
    if(A==NULL) return A;
    TreeNode* right_ = A->right;
    if(A->left){
        A->right = A->left;
        A->left = NULL;
        A = getTree(A->right);
    }
    
    if(right_){
        A->right = right_;
        A = getTree(A->right);
    }
    return A;
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    getTree(A);
    return A;
}
