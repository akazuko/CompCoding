/* A binary tree node
struct node
{
    int data;
    struct Node* left, * right;
}; */

void pleft(node *root){
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->data<<" ";
    if(root->left!=NULL)
        pleft(root->left);
    else if(root->left==NULL && root->right!=NULL)
        pleft(root->right);
}


void pright(node *root){
    if(root->left==NULL && root->right==NULL) return;
    
    if(root->right!=NULL)
        pright(root->right);
    else if(root->right==NULL && root->left!=NULL)
        pright(root->left);

    cout<<root->data<<" ";
}

void pleaves(node *root){
    if(root->left==NULL && root->right==NULL){ cout<<root->data<<" "; return;}
    if(root->left!=NULL) pleaves(root->left);
    if(root->right!=NULL) pleaves(root->right);
}
void printBoundary(node *root) {
//Your code here
    if(root==NULL) return;
    cout<<root->data<<" ";
    if(root->left) pleft(root->left);
    pleaves(root);
    if(root->right) pright(root->right);
}
