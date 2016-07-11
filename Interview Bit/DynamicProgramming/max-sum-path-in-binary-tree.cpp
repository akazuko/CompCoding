/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int genP(TreeNode* A, int &res){
    if(!A) return 0;
    int l = genP(A->left, res);
    int r = genP(A->right, res);
    int max_single = max(max(l,r) + A->val, A->val);
    int max_top = max(max_single, l + r + A->val);
    res = max(res, max_top);
    return max_single;
}
int Solution::maxPathSum(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int res = INT_MIN;
    genP(A, res);
    return res;
}
