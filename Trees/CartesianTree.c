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
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output root pointer of tree.
 */

int partition(int *A, int start, int end){
    int i;
    int pos = -1;
    int max = -1;
    for(i=start; i<=end;++i){
        if(A[i]>max){
            pos=i;
            max=A[i];
        }
    }
    return pos;
}
treenode* buildTreeOne(int *A, int start, int end){
    treenode* root=NULL;
    if(start<=end){
        int pivot = partition(A,start,end);
        root = treenode_new(A[pivot]);
        root->left = buildTreeOne(A, start, pivot-1);
        root->right = buildTreeOne(A, pivot+1, end);
    }
    return root;
}
treenode* buildTree(int* A, int n1) {
    return buildTreeOne(A,0,n1-1);
}
