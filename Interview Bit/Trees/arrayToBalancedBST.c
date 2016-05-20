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
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output root pointer of tree.
 */
 
treenode *insert(treenode* root, int key){
    
    if(root==NULL){
        root = treenode_new(key);
        return root;
    }
    
    treenode *temp1, *temp2;
    temp1=root;
    
    while(temp1){
        temp2=temp1;
        if(temp1->val>key){
            temp1=temp1->left;
        }
        else{
            temp1=temp1->right;
        }
    }
    treenode *res = treenode_new(key);
    if(temp2->val>key){
        temp2->left = res;
    }
    else{
        temp2->right = res;
    }
    return res;
} 
 
treenode* merge(treenode* root, int start, int end, const int* A){
    if(start<=end){
        int mid = (start+end)/2;
        treenode* lol = insert(root,A[mid]);
        if(root==NULL){
            root=lol;
        }
        merge(root, start, mid-1, A);
        merge(root, mid+1, end, A);
        return root;
    }
    return NULL;
}
treenode* sortedArrayToBST(const int* A, int n1) {
    treenode* root=NULL;
    root = merge(root, 0, n1-1, A);
    return root;
}
