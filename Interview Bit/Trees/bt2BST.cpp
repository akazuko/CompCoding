/*Your code here*/
void inorder(Node* node, vector<int> &A){
    if(node==NULL) return;
    inorder(node->left, A);
    A.push_back(node->data);
    inorder(node->right, A);
}
void inorder1(Node* node, vector<int> &A, int &i){
    if(node==NULL) return;
    inorder1(node->left, A, i);
    node->data = A[i];
    i++;
    inorder1(node->right, A, i);
}
Node *binaryTreeToBST (Node *root) {
    if(root==NULL) return NULL;
    vector<int> A;
    inorder(root, A);
    sort(A.begin(), A.end());
    int k = 0;
    inorder1(root, A, k);
    return root;
}
 
