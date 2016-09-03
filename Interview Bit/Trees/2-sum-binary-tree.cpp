/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool P(TreeNode* A, int B, map<int,int> &m){
    if(A==NULL) return false;
    if(m.find(B - A->val)!=m.end()) return true;
    int value = A->val;
    m[value] = 1;
    if(P(A->left, B, m)) return true;
    if(P(A->right, B, m)) return true;
    return false;
}
int Solution::t2Sum(TreeNode* A, int B) {
    map<int,int> m;
    if(P(A, B, m)) return 1;
    return 0;
}

