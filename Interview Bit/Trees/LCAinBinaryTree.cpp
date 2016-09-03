/* A binary tree node
struct node
{
    int data;
    struct Node* left, * right;
}; */


/*you are required to 
complete this function */
Node * LCA(Node* root ,int n1 ,int n2 ) {
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    Node* ll = LCA(root->left,n1,n2);
    Node* rr = LCA(root->right,n1,n2);
    if(ll && rr) return root;
    return ll!=NULL?ll:rr;
}
