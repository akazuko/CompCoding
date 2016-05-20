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
 * @input inorder : Integer array
 * @input n1 : Integer array's ( inorder ) length
 * @input postorder : Integer array
 * @input n2 : Integer array's ( postorder ) length
 * 
 * @Output root pointer of tree.
 */
 
int search(int start, int end, int *A, int val){
    int i=-1;
    for(i=start; i<=end; ++i){
        if(A[i]==val)
            return i;
    }
    return -1;
}
treenode* cTree(int *in, int *post, int start, int end, int *root){
    treenode* node=NULL;
    
    if(start<=end && *root>=0){
        //printf("%d %d %d\n",start, end, post[*root]);    
        int pivot = search(start, end, in, post[*root]);
        node = treenode_new(post[*root]);
        *root-=1;
        node->right = cTree(in, post, pivot+1, end, root);
        if(node->right==NULL) *root+=1;
        *root-=1;
        node->left = cTree(in, post, start, pivot-1, root);
        if(node->left==NULL) *root+=1;
    }
    return node;
}
treenode* buildTree(int* inorder, int n1, int* postorder, int n2) {
    n1--;
    int *root = &n1;
    
    return cTree(inorder, postorder, 0, n1, root);
    // return treenode_new(postorder[*root]);
}
