/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> genP(int start, int end){
    vector<TreeNode*> res;
    
    if(start > end){
        res.push_back(NULL);
        return res;
    }
    for(int i = start; i<=end; ++i){
        vector<TreeNode*> ls = genP(start, i-1);
        vector<TreeNode*> rs = genP(i+1, end);
        for(auto L : ls){
            for(auto R : rs){
                TreeNode* cur = (TreeNode *)malloc(sizeof(TreeNode));
                cur->val = i;
                cur->left = L;
                cur->right = R;
                res.push_back(cur);
            }
        }
    }
    return res;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<TreeNode*> ans;
    if(A==0) return ans;
    return genP(1,A);
}
