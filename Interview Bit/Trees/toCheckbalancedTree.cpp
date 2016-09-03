/* A binary tree node structure
struct Node {
    int data;
    struct Node* left, * right;
}; */

// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree
pair<bool, int> P(struct Node* root){
    if(root==NULL) return make_pair(true, 0);
    auto r1 = P(root->left);
    if(!r1.first) return make_pair(false,0);
    auto r2 = P(root->right);
    if(!r2.first) return make_pair(false,0);
    if(abs(r1.second - r2.second) > 1) return make_pair(false,0); 
    return make_pair(true, max(r1.second, r2.second) + 1);
    
}
bool isBalanced(struct Node *root)
{
    auto l = P(root);
    return l.first;
}

