/* A binary tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */


// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTreee(struct Node *node) {
    if(node==NULL){
        return 0;
    }
    
    int left = toSumTreee(node->left);
    int right = toSumTreee(node->right);
    int t = node->data;
    node->data = left + right;
    return node->data + t;
    
}

void toSumTree(struct Node *node) {
    toSumTreee(node);
}


