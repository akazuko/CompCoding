/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */


/* Should print vertical order such that each vertical line
   is separated by $ */
void verticalOrder(Node *root)
{
    //Your code here
    map<int, string > m;
    queue< pair<Node* ,int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        auto k = q.front();
        int level = k.second;
        Node* temp = k.first;
        q.pop();
        if(temp==NULL) continue;
        m[level] += to_string(temp->data) + " ";
        if(temp->left)
            q.push(make_pair(temp->left, level - 1));
        if(temp->right)
            q.push(make_pair(temp->right, level + 1));
    }
    for(auto k : m) cout<<k.second<<"$";
}
