/*

The structure of a BST node is as follows:

struct node {
int data;
struct node * right, * left;
};


*/

/*You are required to complete
this function*/
node* LCA(node *root, int n1, int n2)
{
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    if(root->data > n1 && root->data < n2) return root;
    if(root->data < n1 && root->data > n2) return root;
    if(root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if(root->data < n1 && root->data < n2) 
        return LCA(root->right, n1, n2);

}
